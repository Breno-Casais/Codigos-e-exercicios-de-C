#include <iostream>
using namespace std;

// try = tentar executar
// catch = pegar algo parar tratar
// throw = lancar um erro que a funcao pode pegar atraves do catch

int fat(int n){
	if(n < 0)
		throw "numero negativo !";
	if ((n == 0) or (n==1))
		return 1;
	else 
		return n*fat(n-1);
}
int main(){

	try
	{
		cout << fat(5) << endl;
		cout << fat(-5) << endl;
	}
	
	catch (const char* e){
		cerr << "Erro: " << e << endl;
	}
	catch (...)
	{
		cout << "erro inesperado";
	}
	
return 0;
}
