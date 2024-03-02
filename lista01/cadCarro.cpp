#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string marca_automovel();
string nome_automovel();
string tipo_combustivel();
int ano_frabicacao();


int main()
{
    struct CadCarro
    {
        string marca;
        string nome;
        string combustivel;
        int ano_frabricacao;
    };
    
    int qtd = 4;
    struct CadCarro vetor_carro[qtd];

    for (int x = 0; x < qtd; x++)
    {
        vetor_carro[x].marca = marca_automovel();
        vetor_carro[x].nome = nome_automovel();
        vetor_carro[x].combustivel = tipo_combustivel();
        vetor_carro[x].ano_frabricacao = ano_frabicacao();
    }

    cout << ""<< endl;
    
    for (int x = 0; x < qtd; x++)
    {
        cout << "Marca: " << vetor_carro[x].marca << endl;
        cout << "Nome: " << vetor_carro[x].nome << endl;
        cout << "Combustivel: " << vetor_carro[x].combustivel << endl;
        cout << "Ano Fabricação: " << vetor_carro[x].ano_frabricacao << endl;
        cout << "========================================" << endl;
    }

    return 0;
}

string marca_automovel() {
    string marca_carro;
    cout << "Digite a marca do carro: ";
    cin >> marca_carro;
    return marca_carro;
}

string nome_automovel() {
    string nome_carro;
    cout << "Digite o nome do carro: ";
    cin >> nome_carro;
    return nome_carro;
}

string tipo_combustivel() {
    string combustivel;
    cout << "Qual combustivel do Carro: ";
    cin >> combustivel;
    return combustivel;
}

int ano_frabicacao() {
    int ano_fab;
    cout << "Digite o ano de fabricação do carro: ";
    cin >> ano_fab;
    return ano_fab;
}
