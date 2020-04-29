#include <iostream>
#include <vector>
#include <string.h>
using namespace std;



class Pessoa{
    protected:
        string nome;
        int idade;
        int cpf;



    public:

        Pessoa(string nome,int idade,int cpf){
            this ->cpf = cpf;
            this ->idade = idade;
            this ->nome = nome;
        }
        void mostrarPessoa(){
            cout <<"Nome: "<< this -> nome << " ";
            cout <<"Idade: "<< this -> idade << " ";
            cout <<"Cpf: "<< this -> cpf << " ";
        }

        string getNome() {
	        return this->nome;
        }
        void setNome(string nome) {
            this->nome = nome;
        }


        int getIdade() {
        	return this->idade;
        }
        void setIdade(int idade) {
        	this->idade = idade;
        }


        int getCpf() {
        	return this->cpf;
        }
        void setCpf(int cpf) {
        	this->cpf = cpf;
        }

};

class Aluno : Pessoa{
    protected:
        int  codigo;
        double notaFinal;
    public:
        Aluno(string nome,int idade,int cpf,int codigo, double notaFinal) : Pessoa(nome , idade, cpf){
            this -> codigo = codigo;
            this -> notaFinal = notaFinal;
        }
        void mostarAluno(){
            this -> mostrarPessoa();
            cout <<"Codigo: "<< this -> codigo << " ";
            cout <<"notaFinal: "<< this -> notaFinal << " ";
            cout<<endl;           
        }
};

void mostrarMenu(){
    
    cout << "1- Cadastrar"<<endl;
    cout << "2- acabar"<<endl;
    cout << "3 - Verificar";
}

void Menualuno(){
    cout << "nome , idade, codigo,  notaFinal";
}

int main(){
    
    
    int verifica = 1;
    int menu;
    while(verifica != 0 ){
        mostrarMenu();
        cin >> menu;       
        if (menu == 1) {
            vector<Aluno*> a1;
            int ajuda , cadastro1;
            string nome;
            int idade,  codigo;
            double notaFinal;
            cout << "digite o seu cpf: " << endl;
            cin >> ajuda;
            cadastro1 = ajuda;
            Menualuno();
            cin >> nome >> idade >> codigo >> notaFinal;
            Aluno *cadastro1 = new Aluno(nome,idade,ajuda,codigo,notaFinal);
            a1.push_back(cadastro1);
            vector<Aluno*>::iterator p1 = a1.begin();
            
        }
    }
    
    Aluno *primeiro = new Aluno("fernando",20,001,01,89);
    return 0 ;
}