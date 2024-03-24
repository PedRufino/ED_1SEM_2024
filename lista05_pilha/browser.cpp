// Ao  navegar  na  internet,  a  cada  site  acessado,  o  endereço  é 
// armazenado em uma pilha. Ao clicar em voltar, pode-se acessar 
// novamente o endereço anteriormente visitado. 

// Faça um programa que simule as funcionalidades de acessar um 
// site  e  voltar.  Ao  empilhar,  armazenar  o  endereço  http.  Ao 
// desempilhar,  retornar  o  endereço  http.  Não  há  limite  de  sites 
// que podem ser acessados.

// Armazene  o  endereço  http.  A  entrada  de  dados  deve  ocorrer 
// dentro da função de empilhamento.

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Hist {
    string url;
    Hist* next;
};

struct Brow {
    Hist* top;
    int size;
};


Brow * navegador() {
    Brow* b = new Brow;
    b->top = nullptr;
    b->size = 0;
    return b;
}

void acessar_pagina(Brow* b, string link){
    Hist* lk = new Hist;
    lk->url = link;
    lk->next = b->top;
    b->top = lk;
    b->size++;
}

string voltar_pagina(Brow* b){
    string temp;
    Hist* lk = new Hist;

    if (b->top == nullptr){
        return "Nenhum site acessado!";
    }

    temp = b->top->url;
    Hist* tempPtr = b->top;
    b->top = b->top->next;
    delete tempPtr;
    b->size--;
    return temp;
}

void limpar_historico(Brow* b){
    while (b->top != nullptr) {
        Hist* temp = b->top;
        b->top = b->top->next;
        delete temp;
        b->size--;
    }
    delete b;
}

void site_atual(Brow* b){
    Hist* temp = b->top;
    if (temp == nullptr) {
        cout << "Nenhum site acessado!" << endl;
        return;
    }
    cout << "Sites acessados:" << endl;
    while (temp != nullptr) {
        cout << temp->url << endl;
        temp = temp->next;
    }
}

int main()
{
    string url;
    Brow* my_browser = navegador();

    site_atual(my_browser);
    acessar_pagina(my_browser, "https://www.xpgamesaves.com/");
    site_atual(my_browser);
    acessar_pagina(my_browser, "https://www.animestc.net/");
    acessar_pagina(my_browser, "https://www.youtube.com/?hl=pt&gl=BR");
    acessar_pagina(my_browser, "https://tsuki-mangas.com/");
    acessar_pagina(my_browser, "https://jsonformatter.curiousconcept.com/");
    acessar_pagina(my_browser, "https://www.udemy.com");
    acessar_pagina(my_browser, "https://curlconverter.com/");
    site_atual(my_browser);

    url = voltar_pagina(my_browser);
    cout << "Pagina Anterior: " << url << endl;

    url = voltar_pagina(my_browser);
    cout << "Pagina Anterior: " << url << endl;
    
    url = voltar_pagina(my_browser);
    cout << "Pagina Anterior: " << url << endl;

    limpar_historico(my_browser);

}
