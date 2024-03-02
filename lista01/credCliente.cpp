#include <iostream>
#include <string>
using namespace std;

struct CredCliente
{
    string nomeCompleto;
    string dataNasc;
    string cpf;
    string nomeBanco;
    int agenciaConta;
    int numeroConta;
    int tipoConta;
};

void inserirDados(CredCliente& cliente)
{
    cout << "Nome Completo: ";
    cin >> cliente.nomeCompleto;
    cout << "Data de Nascimento: ";
    cin >> cliente.dataNasc;
    cout << "CPF: ";
    cin >> cliente.cpf;
    cout << "Nome do Banco: ";
    cin >> cliente.nomeBanco;
    cout << "Agência da Conta: ";
    cin >> cliente.agenciaConta;
    cout << "Número da Conta: ";
    cin >> cliente.numeroConta;
    cout << "Tipo de Conta: ";
    cin >> cliente.tipoConta;
}

int main()
{
    const int qtd = 2;
    CredCliente vetor_pessoa[qtd];

    for (int i = 0; i < qtd; i++)
    {
        cout << "Inserindo dados para a pessoa " << i + 1 << endl;
        inserirDados(vetor_pessoa[i]);
    }

    for (int i = 0; i < qtd; i++)
    {
        cout << "" << endl;
        cout << "Dados da pessoa " << i + 1 << ":" << endl;
        cout << "Nome Completo: " << vetor_pessoa[i].nomeCompleto << endl;
        cout << "Data de Nascimento: " << vetor_pessoa[i].dataNasc << endl;
        cout << "CPF: " << vetor_pessoa[i].cpf << endl;
        cout << "Nome do Banco: " << vetor_pessoa[i].nomeBanco << endl;
        cout << "Agência da Conta: " << vetor_pessoa[i].agenciaConta << endl;
        cout << "Número da Conta: " << vetor_pessoa[i].numeroConta << endl;
        cout << "Tipo de Conta: " << vetor_pessoa[i].tipoConta << endl;
        cout << endl;
    }

    return 0;
}