#include <iostream>
#include <string>
using namespace std;

typedef struct Universidade{
	
	string nome;	
	void mostrarUniversidade(){
		cout<<nome<<endl;
	}
}t_universidade;

typedef struct Aluno{
	
	string nome;
	Universidade universidade;	
	void mostrarAluno(){
		cout << nome;
		universidade.mostrarUniversidade();
	}
}t_aluno;
int main(){
	t_aluno aluno = {"marcos",{"UFLA"}};
	t_aluno *ptraluno;
	
	ptraluno = &aluno;
	ptraluno -> mostrarAluno();
return 0;
}
