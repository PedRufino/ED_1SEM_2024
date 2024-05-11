/*
 * Exercício para nota 04
 *
 * Prof. Me. Orlando Saraiva Jr
 * Aplicado em : 04/05/2024
 */

#include <iostream>
#include <sstream> 

using namespace std;

typedef struct Item {
    int categoria;
    int prioridade;
    string tarefa;
} TAREFA;

struct Node {
    TAREFA tarefa;
    Node *anterior;
    Node *proximo;
};

struct Lista {
    Node *inicio;
    Node *final;
    int tamanho;
};

void inicializar(Lista *);
void inserir_dados(Lista *);
void adicionar_tarefa(Lista *, TAREFA);
TAREFA retirar_tarefa_por_posicao(Lista *, int);
void mostrarLista(Lista *);
void mostrar_dados_tarefa(TAREFA);


void retirar_tarefa_por_posicao2(Lista *, int);
void buscar_tarefas_por_categoria(Lista *, int);
void buscar_tarefas_por_prioridades(Lista *, int);
void encerrar(Lista *);


int main() {
    Lista lista_tarefa; 
    TAREFA tarefa;

    inicializar(&lista_tarefa);
    mostrarLista(&lista_tarefa);
    retirar_tarefa_por_posicao(&lista_tarefa, 5);
    buscar_tarefas_por_categoria(&lista_tarefa, 2);
    buscar_tarefas_por_prioridades(&lista_tarefa, 2);
    inserir_dados(&lista_tarefa);

    mostrarLista(&lista_tarefa);

    tarefa = retirar_tarefa_por_posicao(&lista_tarefa, 5);
    mostrar_dados_tarefa(tarefa);
    tarefa = retirar_tarefa_por_posicao(&lista_tarefa, 1);
    mostrar_dados_tarefa(tarefa);
    tarefa = retirar_tarefa_por_posicao(&lista_tarefa, 8);
    mostrar_dados_tarefa(tarefa);
    tarefa = retirar_tarefa_por_posicao(&lista_tarefa, 8);
    mostrar_dados_tarefa(tarefa);

    mostrarLista(&lista_tarefa);

    retirar_tarefa_por_posicao2(&lista_tarefa, 2);
    mostrarLista(&lista_tarefa);
    buscar_tarefas_por_categoria(&lista_tarefa, 2);
    buscar_tarefas_por_prioridades(&lista_tarefa, 2);
    encerrar(&lista_tarefa);

    return 0;
}


void inicializar(Lista *lista) {
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->final = NULL;
}

void inserir_dados(Lista *lista) {
    TAREFA tarefa;
    for (int x = 0; x<10; x++) {
        tarefa.categoria = 1;
        tarefa.prioridade = 1;
        string str;
        stringstream stream;
        stream << x + 1;
        stream >> str;
        tarefa.tarefa = "Tarefa " + str;
        adicionar_tarefa(lista, tarefa);
    }

    for (int x = 10; x<15; x++) {
        tarefa.categoria = 1;
        tarefa.prioridade = 2;
        string str;
        stringstream stream;
        stream << x + 1;
        stream >> str;
        tarefa.tarefa = "Tarefa " + str;
        adicionar_tarefa(lista, tarefa);
    }

    for (int x = 15; x<25; x++) {
        tarefa.categoria = 2;
        tarefa.prioridade = 2;
        string str;
        stringstream stream;
        stream << x + 1;
        stream >> str;
        tarefa.tarefa = "Tarefa " + str;
        adicionar_tarefa(lista, tarefa);
    }
}

/* [Fix]: Ajustes na função retirar_tarefa_por_posicao para evitar 
   ocorrência de segmentation fault ao lidar com posições inválidas */

TAREFA retirar_tarefa_por_posicao(Lista *lista, int posicao) {
    TAREFA retorno;
    // cout << "Tamanho: " << lista->tamanho <<endl;
    // cout << "Posição: " << posicao <<endl;
    if ( lista->tamanho < posicao){
        cout << endl << "Tamanho da lista menor que a posição informada" << endl;
    } else {
        Node* aux = lista->inicio;
        while (posicao >= 0 && aux != NULL) {
            posicao--;
            if (posicao == 0) {
                // cout <<  endl << "Remover: " << aux->tarefa.tarefa << endl;
                if(aux->anterior != NULL){
                    aux->anterior->proximo = aux->proximo;
                }else{
                    lista->inicio = aux->proximo;
                }
                if(aux->proximo != NULL){
                    aux->proximo->anterior = aux->anterior;
                }else{
                    lista->final = aux->anterior;
                }
                aux->proximo = NULL;
                aux->anterior = NULL;
                retorno = aux->tarefa;
                lista->tamanho = lista->tamanho - 1;
                delete(aux);
                return retorno;
            }
            aux = aux->proximo;
        }
    }
    return retorno;
}

/* ================================================================ */

void adicionar_tarefa(Lista *lista, TAREFA tarefa){
    Node *new_node = new Node;
    if (new_node == NULL) {
        cerr << "Acabou a memória. " << endl; 
        exit(1);
    }
    new_node->tarefa = tarefa;
    new_node->proximo = NULL;
    new_node->anterior = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = new_node;
        lista->final = new_node;
        lista->tamanho = lista->tamanho + 1;
        return;
    } 
    if (lista->tamanho == 1) {
        Node* aux = lista->final;
        lista->final->proximo = new_node;
        new_node->anterior = lista->final;
        lista->final = new_node; 
        lista->tamanho = lista->tamanho + 1;
        return;
    } else {
        Node* aux = lista->final;
        aux->proximo = new_node;
        new_node->anterior = aux;
        lista->final = new_node; 
        lista->tamanho = lista->tamanho + 1;
        return;
    }
}


void mostrarLista(Lista *lista){
    if (lista->inicio != NULL) {
        cout << endl << "Tamanho da lista: " << lista->tamanho << endl;
        Node* cliente_local = lista->inicio;
        while(cliente_local != NULL){
            cout <<"[" << cliente_local->tarefa.tarefa << "]";
            cliente_local = cliente_local->proximo;
        }
        cout << endl << endl;
    } else {
        cout << "Tamanho da lista: " << lista->tamanho << endl;
        cout << "[]" << endl;
    }
}


void mostrar_dados_tarefa(TAREFA tarefa){
    cout << endl;
    cout << "************************************" << endl;
    cout << "Tarefa:\t" << tarefa.tarefa << endl;
    cout << "Categoria:\t" << tarefa.categoria << endl;
    cout << "Prioridade:\t" << tarefa.prioridade << endl;
    cout << endl;
    
}

/* Funções devem ser desenvolvidas a partir daqui */

/*
 * Pedro Rufino da Mata Neto
 * Feito em : 05/05/2024
 */


/* [Feat]: Adicionando função que busca tarefas por categoria */

void buscar_tarefas_por_categoria(Lista *lista, int categoria) {
    if (lista->inicio != NULL) {
        cout << endl << "Tarefas na categoria " << categoria << endl;
        Node* tarefas = lista->inicio;
        while(tarefas != NULL){
            if (tarefas->tarefa.categoria == categoria){
                cout <<"[" << tarefas->tarefa.tarefa << "]";
            }
            tarefas = tarefas->proximo;
        }
        cout << endl << endl;
    }
}

/* [Feat]: Adicionando função que busca tarefas pelo nivel de prioridades */

void buscar_tarefas_por_prioridades(Lista *lista, int prioridade){
    if (lista->inicio != NULL) {
        cout << endl << "Tarefas na categoria " << prioridade << endl;
        Node* tarefas = lista->inicio;
        while(tarefas != NULL){
            if (tarefas->tarefa.prioridade == prioridade){
                cout <<"[" << tarefas->tarefa.tarefa << "]";
            }
            tarefas = tarefas->proximo;
        }
        cout << endl << endl;
    }
}


void retirar_tarefa_por_posicao2(Lista *lista, int posicao) {
    if ( lista->tamanho < posicao){
        cout << endl << "Tamanho da lista menor que a posição informada" << endl;
    } else {
        Node* aux = lista->inicio;
        while (posicao >= 0 && aux != NULL) {
            posicao--;
            if (posicao == 0) {
                cout <<  endl << "Removido: " << aux->tarefa.tarefa << endl << endl;
                if(aux->anterior != NULL){
                    aux->anterior->proximo = aux->proximo;
                }else{
                    lista->inicio = aux->proximo;
                }
                if(aux->proximo != NULL){
                    aux->proximo->anterior = aux->anterior;
                }else{
                    lista->final = aux->anterior;
                }
                aux->proximo = NULL;
                aux->anterior = NULL;
                lista->tamanho = lista->tamanho - 1;
                delete(aux);
            }
            aux = aux->proximo;
        }
    }
}

/* [Feat]: Adicionando função para a liberação de memoria */

void encerrar(Lista* lista) {
    if (lista != nullptr) {
        Node* atual = lista->inicio;
        while (atual != nullptr) {
            Node* proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
    }
}