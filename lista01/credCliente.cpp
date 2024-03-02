#include <iostream>
#include <string>
using namespace std;

struct CredCliente {
    string nomeCompleto;
    string dataNasc;
    string cpf;
    string nomeBanco;
    int agenciaConta;
    int numeroConta;
    int tipoConta;
    double valorCredito;
    int numParcelas;
    double valorParcela;
};

void inserirDados(CredCliente& cliente) {
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
    cout << "Valor do Crédito: ";
    cin >> cliente.valorCredito;
    cout << "Número de Parcelas (1 a 12): ";
    cin >> cliente.numParcelas;

    while (cliente.numParcelas < 1 || cliente.numParcelas > 12) {
        cout << "Número de Parcelas inválido. Insira novamente (1 a 12): ";
        cin >> cliente.numParcelas;
    }

    cliente.valorParcela = cliente.valorCredito / cliente.numParcelas;
}

int main() {
    const int qtd = 2;
    CredCliente vetor_pessoa[qtd];

    for (int i = 0; i < qtd; i++) {
        cout << "Inserindo dados para a pessoa " << i + 1 << endl;
        inserirDados(vetor_pessoa[i]);
    }

    for (int i = 0; i < qtd; i++) {
        cout << "" << endl;
        cout << "Dados da pessoa " << i + 1 << ":" << endl;
        cout << "Nome Completo: " << vetor_pessoa[i].nomeCompleto << endl;
        cout << "Data de Nascimento: " << vetor_pessoa[i].dataNasc << endl;
        cout << "CPF: " << vetor_pessoa[i].cpf << endl;
        cout << "Nome do Banco: " << vetor_pessoa[i].nomeBanco << endl;
        cout << "Agência da Conta: " << vetor_pessoa[i].agenciaConta << endl;
        cout << "Número da Conta: " << vetor_pessoa[i].numeroConta << endl;
        cout << "Tipo de Conta: " << vetor_pessoa[i].tipoConta << endl;
        cout << "Valor do Crédito: " << vetor_pessoa[i].valorCredito << endl;
        cout << "Número de Parcelas: " << vetor_pessoa[i].numParcelas << endl;
        cout << "Valor da Parcela: " << vetor_pessoa[i].valorParcela << endl;
        cout << endl;
    }

    return 0;
}

