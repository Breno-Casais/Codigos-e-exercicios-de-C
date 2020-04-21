#include <iostream >
using namespace std;
class Pessoa{
	private:
		int idade;
		int *vet;
	public:
		Pessoa(int idade){
			this->idade = idade;
			vet = new int[10];
		}
		~Pessoa(){
			delete [] vet;
		}
		
		int obterIdade(){
			return idade;
		}
};
int main(){
	int * p = new int[10];
	*p = 1;
	*(p+1) = 2;
	*(p+2) = 3;
	//cout << *p << endl << *(p+1) << endl << *(p+2);
	delete [] p;
	
	Pessoa *pe = new Pessoa(20);
	cout << pe->obterIdade();
	delete pe;
	
	
	
return 0;
}
