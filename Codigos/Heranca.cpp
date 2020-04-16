#include <iostream>
#include <string.h>
using namespace std;
class Animal{
	protected : 
		int idade;
		char* nome;
		bool voa;
	public :
		Animal(const char* nome){
			cout << "entrei no contrutor de animal"<<endl;
			strcpy(this->nome,nome);
			idade = 0;
		}
		const char* getNome(){
			return this -> nome;
		}
		bool getVoa(){
			return this -> voa;
		}
		int getIdade(){
			return this -> idade;
		}
};

class Cachorro : public Animal{
	protected:
		string pelo;
	public:
		Cachorro(const char*nome,string pelo) : Animal(nome){
			cout << "entrei no contrutor de cachrro"<<endl;			
			this->pelo = pelo;
		}
		string getPelo(){
			return this->pelo;
		}
};

int main(){	
	Cachorro *a1 = new Cachorro("fernando","liso");
	cout << a1->getNome()<<endl;
	cout << a1->getIdade()<<endl;
	cout << a1->getPelo()<<endl;
	cout << a1->getVoa()<<endl;
	
	
	return 0;
}
