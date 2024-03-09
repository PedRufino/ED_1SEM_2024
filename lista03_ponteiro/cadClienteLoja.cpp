#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


struct parcelas
{  
    string local;
    string data;
    double valorParcela;
};

typedef struct CadCliLoja
{
    string nome;
    string endereco;
    string cidade;
    string estado;
    double valorTotal;
    parcelas* totalParcelas;
} CADCLILOJA;

static int qtd = 0;
static int qtdParcelas = 0;

void cadastro_cliente(CadCliLoja& cad_cliente);
void quantidade_parcela(CadCliLoja& cad_cliente);

int main()
{   
    int i;
    
    // Solicitar o número de clientes
    cout << "Digite a quantidade de clientes: ";
    cin >> qtd;
    cout <<"========================"<< endl;

    // aloca memória para o vetor de minha_loja (Informar qtd de clientes)
    CADCLILOJA* minha_loja = new CADCLILOJA[qtd];

    for (i = 0; i < qtd; i++)
    {
        cadastro_cliente(minha_loja[i]);
        
        // Solicitar a quantidade de parcelas
        cout << "Digite a quantidade de parcelas: ";
        cin >> qtdParcelas;

        // Alocar memória para o array de quantidade de parcelas
        minha_loja[i].totalParcelas = new parcelas[qtdParcelas];

        quantidade_parcela(minha_loja[i]);
    }
    
    for (i = 0; i < qtd; i++) {
        cout << endl;
        cout << "nome = " << minha_loja[i].nome << endl;
        cout << "endereco = " << minha_loja[i].endereco << endl;
        cout << "cidade = " << minha_loja[i].cidade << endl;
        cout << "estado = " << minha_loja[i].estado << endl;
        for (int x = 0; x < qtdParcelas; x++)
        {   
            cout << endl;
            cout << x+1 <<" Parcela:" << endl;
            cout << "local = " << minha_loja[i].totalParcelas[x].local << endl;
            cout << "data = " << minha_loja[i].totalParcelas[x].data << endl;
            cout << "valorParcela = " << minha_loja[i].totalParcelas[x].valorParcela << endl;
        }
        cout << endl;
        cout <<"========================"<< endl;
    }
    
    delete[] minha_loja;

    return 0;
}

void cadastro_cliente(CadCliLoja& cad_cliente){
    cout << "Digite o nome do cliente: ";
    cin >> cad_cliente.nome;
    cout << "Digite o endereço do cliente: ";
    cin >> cad_cliente.endereco;
    cout << "Digite a cidade do cliente: ";
    cin >> cad_cliente.cidade;
    cout << "Digite o estado do cliente: ";
    cin >> cad_cliente.estado;
    cout << "Digite o valor da compra: ";
    cin >> cad_cliente.valorTotal;
}

void quantidade_parcela(CadCliLoja& cad_cliente){
    double valorParcela = cad_cliente.valorTotal / qtdParcelas;

    for (int i = 0; i < qtdParcelas; i++)
    {
        cout << i+1 <<" Parcela:" << endl;
        cout << "Digite o local da compra: ";
        cin >> cad_cliente.totalParcelas[i].local;
        cout << "Digite a data da compra: ";
        cin >> cad_cliente.totalParcelas[i].data;
        cad_cliente.totalParcelas[i].valorParcela = valorParcela;
    }
}