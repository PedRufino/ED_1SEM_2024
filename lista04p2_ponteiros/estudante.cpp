// Você é encarregado de criar um programa em C++ para gerenciar informações de estudantes de uma escola.
// Cada estudante deve ter seu nome completo, idade e média final armazenados de forma organizada. Para
// isso, você deve criar uma estrutura (struct) chamada Estudante que contenha os seguintes campos:

// Nome Completo: Uma variável do tipo string para armazenar o nome completo do estudante.
// Idade: Uma variável do tipo int para armazenar a idade do estudante.
// Média Final: Uma variável do tipo float para armazenar a média final do estudante.

// O programa pode armazenar somente um estudante.

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct estudante
{
    string nome_completo;
    int idade;
    float media;
};

void informaEstudante(estudante& cadEstudante);

int main()
{
    int qtd = 1;
    estudante vetor_aluno[qtd];

    for (int i = 0; i < qtd; i++)
    {
        informaEstudante(vetor_aluno[i]);
    }

    for (int i = 0; i < qtd; i++)
    {
        cout << endl;
        cout << "Dados do aluno :" << endl;
        cout << "Nome Completo: " << vetor_aluno[i].nome_completo << endl;
        cout << "Idade: " << vetor_aluno[i].idade << endl;
        cout << "Média: " << vetor_aluno[i].media << endl;
        cout << endl;
    }
    
    

    return 0;
}

void informaEstudante(estudante& cadEstudante){
    float nota1, nota2, result;

    cout << "Digite o nome do estudante: ";
    getline(cin, cadEstudante.nome_completo);
    cout << "Digite a idade do estudante: ";
    cin >> cadEstudante.idade;
    cout << "Digte a primeira nota: ";
    cin >> nota1;
    cout << "Digte a segunda nota: ";
    cin >> nota2;
    result = (nota1+nota2)/2;
    cout << "Média do aluno é: " << result;
    cadEstudante.media = result;
}
