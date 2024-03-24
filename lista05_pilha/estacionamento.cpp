// Um estacionamento possui uma única entrada/saída e a
// capacidade máxima para guardar dez carros. Faça um programa
// que simule a entrada ( empilhar ) e saída ( desempilhar) de
// carros deste estacionamento.

// Armazene a placa, modelo e ano de cada carro estacionado. A
// entrada de dados deve ocorrer dentro da função de
// empilhamento.

// Funções esperadas: 
    // Estacionar carro
    // Chek-out de carro
    // Listar carros estacionados

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#define STACK_MAX 10

typedef struct estacionamento
{
    string placa[STACK_MAX];
    string modelo[STACK_MAX];
    int ano[STACK_MAX];
    int size;
} Park;

void inicializar(Park *s){
    s->size = 0;
}

void estacionar_carro(Park *s,  string pl, string mod, int an){
    if (s->size < STACK_MAX){
        s->placa[s->size] = pl;
        s->modelo[s->size] = mod;
        s->ano[s->size] = an;
        s->size++;
    } else{
        cout << "Erro: Pilha Cheia\n";
    }
}

string chekOut_carro(Park *s){
    if (s->size > 0){
        cout << "Carro que saiu do estacionamento:" << endl;
        cout << "Placa: " << s->placa[s->size - 1] << endl;
        cout << "Modelo: " << s->modelo[s->size - 1] << endl;
        cout << "Ano: " << s->ano[s->size - 1] << endl;
        s->size--;
    } else{
        cout << "Erro: Estacionamento vazio!" << endl;
    }
}

void carros_estacionados(Park *s){
    if (s->size > 0){
        cout << "Carros estacionados:" << endl;
        for (int i = s->size - 1; i >= 0; i--) {
            cout << "Placa: " << s->placa[i] << endl;
            cout << "Modelo: " << s->modelo[i] << endl;
            cout << "Ano: " << s->ano[i] << endl;
        }
    } else{
        cout << "Nenhum carro estacionado no momento." << endl;
    }
}

int main()
{
    Park vagas;

    inicializar(&vagas);

    estacionar_carro(&vagas, "PLS-0502", "Corsa", 2004);
    estacionar_carro(&vagas, "ASD-6545", "Meriva", 2021);
    estacionar_carro(&vagas, "ERT-1594", "Honda", 2003);
    estacionar_carro(&vagas, "FVE-7534", "Parati", 2024);

    carros_estacionados(&vagas);

    chekOut_carro(&vagas);
    chekOut_carro(&vagas);
    chekOut_carro(&vagas);
}
