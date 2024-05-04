/*
 * Desafio Árvore Binária.
 *
 * Pedro Rufino
 *
 */
#include <iostream>

using namespace std;

struct Node {
    string nome;
    int idade;
    Node* left;
    Node* right;
};

Node* createNode(string, int);
Node* insert(Node*, string, int);
void preOrderTraversal(Node*);
void inOrderTraversal(Node*);
void postOrderTraversal(Node*);
Node* search(Node*, int);
bool search2(Node*, string);
void destroyTree(Node*);

int main() {
    Node* root = NULL;
    root = insert(root, "Pedro", 50);
    insert(root, "Ana", 30);
    insert(root, "Marcos", 20);
    insert(root, "Rafael", 40);
    insert(root, "Maria", 70);
    insert(root, "Gabiela", 60);
    insert(root, "Antonio", 80);

    // Percorrer a árvore em pré-ordem
    cout << "Pré-ordem: ";
    preOrderTraversal(root);
    cout << endl;

    // Percorrer a árvore em ordem
    cout << "Em ordem: ";
    inOrderTraversal(root);
    cout << endl;

    // Percorrer a árvore em pós-ordem
    cout << "Pós-ordem: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "" << endl;
    // Buscar valores na árvore
    cout << "Busca por 30: ";
    Node *node30 = search(root, 30);
    if (node30) {
        cout << "Encontrado: (" << node30->nome << ", " << node30->idade << ")"<< endl;
    } else {
        cout << "Não encontrado" << endl;
    }
    cout << "Busca por 45: ";
    Node *node45 = search(root, 45);
    if (node45) {
        cout << "Encontrado: " << node45->nome << ", " << node45->idade << endl;
    } else {
        cout << "Não encontrado" << endl;
    }

    cout << "" << endl;
    // Buscar Nome na árvore
    cout << "Busca por Maria: " << (search2(root, "Maria") ? "" : "Não encontrado") << endl;
    cout << search2(root, "Carlos");
    cout << "Busca por Carlos: " << (search2(root, "Carlos") ? "Encontrado:" : "Não encontrado") << endl;
    // Liberar memória alocada para a árvore
    destroyTree(root);

    return 0;
}


Node* createNode(string nome, int idade) {
    Node* newNode = new Node;
    newNode->nome = nome;
    newNode->idade = idade;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, string nome, int idade) {
    if (root == NULL) {
        return createNode(nome, idade);
    }

    if (idade < root->idade) {
        root->left = insert(root->left, nome, idade);
    } else if (idade > root->idade) {
        root->right = insert(root->right, nome, idade);
    }

    return root;
}

void preOrderTraversal(Node* root) {
    if (root != NULL) {
        cout << "(" << root->nome << ", " << root->idade << ")" << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        cout << "(" << root->nome << ", " << root->idade << ")" << " ";
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << "(" << root->nome << ", " << root->idade << ")" << " ";
    }
}

Node* search(Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (root->idade == value) {
        return root;
    } else if (value < root->idade) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}


bool search2(Node* root, string nome) {
    if (root == NULL) {
        return false;
    }

    if (root->nome == nome) {
        cout << "(" << root->nome << ", " << root->idade << ")";
        return true;
    }

    // Verifica recursivamente à esquerda e à direita
    bool foundLeft = search2(root->left, nome);
    bool foundRight = search2(root->right, nome);

    return foundLeft || foundRight;
}



void destroyTree(Node* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}