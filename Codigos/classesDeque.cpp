//deque = fila de duas pontas

#include <iostream>
#include <deque>
using namespace std;
void verificar(deque <int> fila){
	if(fila.empty())
		cout << "fila vazia" <<endl;
	else
		cout << "fila NAO vazia" <<endl;
}
void mostrar(deque <int> fila){
	deque<int>::iterator it = fila.begin();
	
	for(it = fila.begin(); it != fila.end(); it++){
		cout << *it <<" ";
	} 
	cout << endl;
}

int main(){
	deque <int> fila;
	
	cout << "antes de inserir os elementos: " ;

	verificar(fila);
	
	//inserir elemnetos ao final da fila
	
	fila.push_back(10);
	fila.push_back(20);
	
	//inserir elementos ao inicio da fila
	fila.push_front(30);
	fila.push_front(40);
	
	//mostrando os elementos
	cout << "mostrando os elementos inseridos: ";
	deque<int>::iterator it = fila.begin();
	
	for(it = fila.begin(); it != fila.end(); it++){
		cout << *it <<" ";
	} 
	cout << endl;
	// limpar toda a fila;
	fila.clear();
	cout << "depois de limpar a fila: " << " ";
	verificar(fila);
	
	//removendo o segundo elemnto
	fila.push_front(30);
	fila.push_front(40);
	fila.erase(fila.begin() + 1);
	
	//mostrando os elementos
	cout << "Removendo o segundo elemento da fila: ";
	mostrar(fila);
	
	//inserindo um elemento na segunda posicao
	cout <<"Inserindo o segundo elemento da fila: ";
	
	it = fila.begin() + 1;
	fila.insert(it,10);
	
	mostrar(fila);
	
return 0;
}
