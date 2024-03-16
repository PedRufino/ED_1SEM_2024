// Você foi designado para criar um programa em C++ para gerenciar informações sobre produtos em um
// estoque. O objetivo é criar uma estrutura de dados que permita armazenar detalhes sobre cada produto, como
// nome, preço e quantidade em estoque, utilizando alocação dinâmica de memória com ponteiros em heap e
// garantindo a utilização dos tipos string, integer e float.

// Para isso, você deve criar uma estrutura (struct) chamada Produto que inclua os seguintes campos:
// Nome: Uma variável do tipo string para armazenar o nome do produto.
// Preço: Uma variável do tipo float para armazenar o preço do produto.
// Quantidade em Estoque: Uma variável do tipo integer para armazenar a quantidade disponível do produto em
// estoque.

// O software deve armazenar 10 produtos diferentes, alocando-se na memória heap.

#include <iostream>
#include <string>

using namespace std;

struct prodEstoque {
    string nome;
    float preco;
    int quantidade;
};

void adicionaEstoque(prodEstoque &cad_prod);

int main() {
    string choice;
    int contador = 0;
    prodEstoque *estoque = new prodEstoque[10];

    do {
        if (contador >= 10) {
            cout << "Limite de produtos alcançado." << endl;
            break;
        }

        adicionaEstoque(estoque[contador]);

        cout << "Deseja continuar [s/n]: ";
        cin >> choice;

        contador++;
    } while (choice == "s" || choice == "S");

    cout << "Produtos Adicionados:" << endl;
    for (int i = 0; i < contador; i++) {
        cout << "Produto " << i + 1 << ":" << endl;
        cout << "Nome: " << estoque[i].nome << endl;
        cout << "Preço: " << estoque[i].preco << endl;
        cout << "Quantidade: " << estoque[i].quantidade << endl;
    }

    delete[] estoque;

    return 0;
}

void adicionaEstoque(prodEstoque &cad_prod) {
    cout << "Digite o nome do produto: ";
    getline(cin, cad_prod.nome);
    cout << "Digite o preço do produto: ";
    cin >> cad_prod.preco;
    cout << "Digite a quantidade do produto: ";
    cin >> cad_prod.quantidade;
}