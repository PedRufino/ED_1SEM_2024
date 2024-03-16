// Você foi designado para desenvolver um programa em C++ para gerenciar informações sobre os funcionários
// de uma empresa. O objetivo é criar uma estrutura de dados que permita armazenar detalhes sobre cada
// funcionário, como nome, cargo, idade, número de identificação e salário, utilizando alocação dinâmica de
// memória com ponteiros em heap.

// Para isso, você deve criar uma estrutura (struct) chamada Funcionario que inclua os seguintes campos:
// Nome: Uma variável do tipo string para armazenar o nome completo do funcionário.
// Cargo: Uma variável do tipo string para armazenar o cargo que o funcionário ocupa na empresa.
// Idade: Uma variável do tipo integer para armazenar a idade do funcionário.
// Número de Identificação: Uma variável do tipo integer para armazenar o número de identificação único do
// funcionário.
// Salário: Uma variável do tipo float para armazenar o salário do funcionário.

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct funcEmpresa
{
    string nome;
    string cargo;
    int idade;
    int num_identificacao;
    float salario;
};

void detalhesFuncionario(funcEmpresa& detalheFunc);

int main()
{
    int qtd = 0;

    cout << "Digite a quantidade de funcionarios: ";
    cin >> qtd;
    cout <<"========================"<< endl;

    funcEmpresa *empresa = new funcEmpresa[qtd];

    for (int i = 0; i < qtd; i++)
    {
        detalhesFuncionario(empresa[i]);
    }

    for (int i = 0; i < qtd; i++)
    {
        cout << endl;
        cout << "Dados do funcionario:" << endl;
        cout << "Nome Completo: " << empresa[i].nome << endl;
        cout << "Idade: " << empresa[i].idade << endl;
        cout << "Cargo: " << empresa[i].cargo << endl;
        cout << "Número de identificação: " << empresa[i].num_identificacao << endl;
        cout << "salario: " << empresa[i].salario << endl;
        cout << endl;
    }
    
    delete[] empresa;

    return 0;
}

void detalhesFuncionario(funcEmpresa& detalheFunc){
    cout << "Digite o nome do funcionario: ";
    cin >> detalheFunc.nome;
    cout << "Digite a idade do funcionario: ";
    cin >> detalheFunc.idade;
    cout << "Digte o cargo do funcionario: ";
    cin >> detalheFunc.cargo;
    cout << "Digte o numero de identificação do funcionario: ";
    cin >> detalheFunc.num_identificacao;
    cout << "Digte o salário do funcionario: ";
    cin >> detalheFunc.salario;
}
