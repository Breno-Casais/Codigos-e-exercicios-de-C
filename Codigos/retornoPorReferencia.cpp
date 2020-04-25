#include <iostream>
using namespace std;

typedef struct pessoas{
	string nome;
	int idade;
	double peso,altura;
	
}t_pessoas;

double& imc(t_pessoas & pessoas){
	
	double res = pessoas.peso / (pessoas.altura*pessoas.altura);
	double& imc = res;
	
	return imc;
}
int main(){
	t_pessoas pessoa{"Joao",20,85.3,1.75};
	cout << imc(pessoa);
return 0 ;
}
