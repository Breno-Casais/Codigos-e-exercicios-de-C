#include <iostream>
using namespace std;

// a funcao inline serve para que no int main a funcao seja copiada e nao chamada
//isso acarreta em um tempo muito maior de execução
//entretando em codigos muito grandes pode acarretar em um grande espaço na memoria 

inline void foo(){
	
	cout << "aprendendo c++";
}
int main(){

	foo();
	
return 0;
}
