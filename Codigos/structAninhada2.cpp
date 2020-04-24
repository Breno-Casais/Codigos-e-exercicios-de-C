#include  <iostream>
using namespace std;
typedef struct Pessoa{
	struct Carro{
		double preco;
	};
	struct Casa{
		double preco;
	};
	
	struct Carro carro;
	struct Casa casa;
}t_pessoa;

	
int main(){
	t_pessoa pessoa;
	pessoa.carro.preco = 25000;
	pessoa.casa.preco = 10000;
	
	cout << pessoa.carro.preco<<endl;
	cout << pessoa.casa.preco;
	return 0;
}
