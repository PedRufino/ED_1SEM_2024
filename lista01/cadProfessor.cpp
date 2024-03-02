#include <iostream>
#include <string>
using namespace std;

struct cadprofessor
{
    string nomeCompleto;
    string disciplina;
    int idade;
    string endereco;
    string email;
};

void inserirProf(cadprofessor& prof){
    cout << "Nome do Professor: ";
    cin >> prof.nomeCompleto;
    cout << "Nome do Professor: ";
    cin >> prof.disciplina;
    cout << "Nome do Professor: ";
    cin >> prof.idade;
    cout << "Nome do Professor: ";
    cin >> prof.endereco;
    cout << "Nome do Professor: ";
    cin >> prof.email;
}

int main()
{
    int qtd = 2;
    struct cadprofessor vetor_prof[qtd];

    for (int i = 0; i < qtd; i++)
    {   
        cout << "Inserindo dados do professor " << i + 1 << endl;
        inserirProf(vetor_prof[i]);
    }
    
    for (int i = 0; i < qtd; i++)
    {
        cout << endl;
        cout << "Dados da pessoa " << i + 1 << ":" << endl;
        cout << "Nome Completo: " << vetor_prof[i].nomeCompleto << endl;
        cout << "Data de Nascimento: " << vetor_prof[i].disciplina << endl;
        cout << "Nome do Banco: " << vetor_prof[i].idade << endl;
        cout << "Agência da Conta: " << vetor_prof[i].endereco << endl;
        cout << "Número da Conta: " << vetor_prof[i].email << endl;
        cout << endl;
    }
    
    return 0;
}
