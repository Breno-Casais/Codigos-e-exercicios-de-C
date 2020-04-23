#include <iostream>
#include <vector>
using namespace std;
class noh{
	private:
		int tamanho =0;
		noh *proximo;
		int d;
	public:
		noh(int d){
			this->d = d;
			proximo = NULL;
			tamanho++;
			
		}
	
};

class Pessoas{
	protected:
		string nome;
		int cpf;
	public:
		Pessoas (string nome,int cpf) {
			this -> cpf = cpf;
			this -> nome = nome;
		}
		
		void mostrarPessoa(){
			cout << this-> nome << " ";
			cout << this-> cpf << " ";
		}
};

class Alunos : public Pessoas{
	protected : 
		int cadastroDeEntrada;
		int notaFinal;
	public: 
		Alunos(string nome,int cpf,int cadastroDeEntrada,int notaFinal) : Pessoas(nome,cpf){
			this->cadastroDeEntrada = cadastroDeEntrada;
			this->notaFinal = notaFinal;
		}
		void mostraralunos(){
			mostrarPessoa();
			cout << this-> cadastroDeEntrada << " ";
			cout << this-> notaFinal << endl;	
			cout<<"-----------------";
			cout<<endl;
			
		}
};

class Professores : public Pessoas{
	protected : 
		int cadastroDeProfessor;
		int salario;
	public: 
		Professores(string nome,int cpf,int cadastroDeProfessor,int salario) : Pessoas(nome,cpf){
			this -> cadastroDeProfessor = cadastroDeProfessor;
			this -> salario = salario;
		}
		void mostrarProfessores(){
			mostrarPessoa();
			cout << this-> cadastroDeProfessor << " ";
			cout << this-> salario << endl;		
			cout<<"-----------------";
			cout<<endl;	
		}	
	
};


int main(){
	vector <Professores*> vetProfessores;
	vector <Professores*>::iterator itProfessores;
	vector <Alunos*> vetAlunos;
	vector <Alunos*>::iterator itAlunos;
	
	Alunos* a1 = new Alunos("breno",123,001,94);
	Alunos* a2 = new Alunos("joao",124,002,80);
	Alunos* a3 = new Alunos("fernando",125,003,80);
	
	vetAlunos.push_back(a1);
	vetAlunos.push_back(a2);
	vetAlunos.push_back(a3);
	
	Professores *p1 = new Professores("guilerme",777,100,9000);
	Professores *p2 = new Professores("gustavo",778,200,9000);
	
	vetProfessores.push_back(p1);
	vetProfessores.push_back(p2);
	
	for (itAlunos = vetAlunos.begin(); itAlunos < vetAlunos.end();itAlunos++)
	{
		(*itAlunos) -> mostraralunos();
	}
	cout<<endl;
	cout<<endl;
	
	cout << "MOstrando professores"; 
	
	cout<<endl;
	cout<<endl;
	cout<<endl;


	for (itProfessores = vetProfessores.begin(); itProfessores < vetProfessores.end();itProfessores++)
	{
		(*itProfessores) -> mostrarProfessores();
	}	

	
	
return 0;
}
