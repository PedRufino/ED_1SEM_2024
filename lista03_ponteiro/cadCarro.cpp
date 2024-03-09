#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct revisao
{
    string local;
    string data;
};

typedef struct carro
{
    string placa;
    int ano;
    string marca;
    revisao* inspecao;
} CARRO;

void cadastro_carro(carro& cad_carro);
void marca_revisao(carro& cad_carro);

static int contador = 0;
static int rev = 0;

int main()
{   
    int i;

    // Solicitar o número de carro
    cout << "Digite a quantidade de carros: ";
    cin >> contador;
    cout <<"========================"<< endl;

    // aloca memória para o vetor de carros (Informar qtd de carros)
    CARRO* vetor_carro = new CARRO[contador];

    for (i = 0; i < contador; i++)
    {
        cadastro_carro(vetor_carro[i]);

        // Solicitar o número de inspeções para este carro
        cout << "Digite a quantidade de Revisões: ";
        cin >> rev;

        // Alocar memória para o array de inspeções deste carro
        vetor_carro[i].inspecao = new revisao[rev];

        marca_revisao(vetor_carro[i]);
    }
    
    for (i = 0; i < contador; i++) {
        cout << endl;
        cout << "Marca = " << vetor_carro[i].marca << endl;
        cout << "Placa = " << vetor_carro[i].placa << endl;
        cout << "Ano = " << vetor_carro[i].ano << endl;
        for (int x = 0; x < rev; x++)
        {   
            cout << "Revisao "<< x+1 <<":" << endl;
            cout << "local "<< x <<" = " << vetor_carro[i].inspecao[x].local << endl;
            cout << "data "<< x <<" = " << vetor_carro[i].inspecao[x].data << endl;
        }
        cout << endl;
    }

    delete[] vetor_carro;
    
    return 0;
}

void cadastro_carro(carro& cad_carro){
    cout << "Digite a marca do carro: ";
    cin >> cad_carro.marca;
    cout << "Digite a placa do carro: ";
    cin >> cad_carro.placa;
    cout << "Digite o ano do carro: ";
    cin >> cad_carro.ano;
}

void marca_revisao(carro& cad_carro){
    for (int i = 0; i < rev; i++)
    {
        cout << "Revisao "<< i+1 <<":" << endl;
        cout << "Digite a data da revisão do carro: ";
        cin >> cad_carro.inspecao[i].data;
        cout << "Digite o local da revisão do carro: ";
        cin >> cad_carro.inspecao[i].local;
    }
}