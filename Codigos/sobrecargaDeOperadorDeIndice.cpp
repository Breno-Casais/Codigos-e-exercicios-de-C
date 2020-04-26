// Sobrecarga de operador de indice []

#include <iostream>
#include <stdlib.h>//funcao exit
using namespace std;

class Vetor
{
private : 
	int *vet;
	int max;
	
public:
	Vetor(int max = 100){
		if (max < 0)
		{
			cout << "Erro : limite maximo nemor do que 0" <<endl;
		}
		else if(max > 1000000)
		{
			cout << "Erro : limite maximo maior do que 1000000" <<endl;
			exit(1);
		}
		
		this -> max = max;
		
		//alocar espaco
		
		vet = (int*)malloc(max * sizeof(int));
	}
	
	~Vetor()
	{
		delete [] vet;
	}
	bool inserir(int e,int pos){
		if(pos < max && pos >=0)
		{
			vet[pos] = e;
			return true;
		}
		
		else
		{
			return false;
		}
	}
	
	int & operator[](int i){
		if(i < 0 || i>max){
			cout << "Erro : acesso invalido"<<endl;
			exit(1);
		}
	}
};

int main(){
	Vetor v(10);
	v.inserir(10,0);
	cout<<"teste";
	return 0 ;
}
