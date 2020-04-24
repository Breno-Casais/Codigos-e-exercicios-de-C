#include  <iostream>
using namespace std;

typedef struct Curso{
	string nome;
	double preco;
	void mostrar(){
		cout << preco << endl;
		cout << nome << endl;
	}
}t_curso;

typedef struct estudante{
	string nome ;
	Curso curso;
	void mostrarEstudante(){
		curso.mostrar();
		cout << nome << endl; 
	}
	
}t_estudante;
int main(){
	t_estudante e;
	e.nome = "fernando";
	e.curso.nome = "matematica";
	e.curso.preco = 100;
	
	e.mostrarEstudante();
return 0;
}
