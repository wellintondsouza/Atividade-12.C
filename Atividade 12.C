#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Aluno {
    string nome;
    vector<double> notas;
};

void adicionarAlunos(vector<Aluno>& alunos) {
    for (int i = 0; i < 5; ++i) {
        Aluno aluno;
        cout << "Digite o nome do aluno " << i+1 << ": ";
        cin >> aluno.nome;
        cout << "Digite as notas do aluno " << aluno.nome << " (separadas por espaco): ";
        for (int j = 0; j < 4; ++j) {
            double nota;
            cin >> nota;
            aluno.notas.push_back(nota);
        }
        alunos.push_back(aluno);
    }
}

void editarNotas(vector<Aluno>& alunos) {
    string nome;
    cout << "Digite o nome do aluno que deseja editar as notas: ";
    cin >> nome;
    for (int i = 0; i < alunos.size(); ++i) {
        if (alunos[i].nome == nome) {
            cout << "Digite as novas notas do aluno (separadas por espaco): ";
            for (int j = 0; j < 4; ++j) {
                cin >> alunos[i].notas[j];
            }
            return;
        }
    }
    cout << "Aluno nao encontrado." << endl;
}

void calcularMediaEStatus(const Aluno& aluno) {
    double soma = 0;
    for (int i = 0; i < aluno.notas.size(); ++i) {
        soma += aluno.notas[i];
    }
    double media = soma / aluno.notas.size();
    cout << "Aluno: " << aluno.nome << ", Media: " << media << ", Estado: ";
    if (media >= 7.0) {
        cout << "Aprovado";
    } else if (media < 5.0) {
        cout << "Reprovado";
    } else {
        cout << "Recuperacao";
    }
    cout << endl;
}

int main() {
    vector<Aluno> alunos;
    int opcao;

    do {
        cout << "\nMenu:\n1. Digitar nome e notas dos 5 alunos\n2. Editar notas\n3. Sair\nEscolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarAlunos(alunos);
                break;
            case 2:
                editarNotas(alunos);
                break;
            case 3:
                cout << "Saindo do programa.";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.";
        }

        if (opcao == 1 || opcao == 2) {
            cout << "\nEstado dos alunos:\n";
            for (int i = 0; i < alunos.size(); ++i) {
                calcularMediaEStatus(alunos[i]);
            }
        }

    } while (opcao != 3);

    return 0;
}
