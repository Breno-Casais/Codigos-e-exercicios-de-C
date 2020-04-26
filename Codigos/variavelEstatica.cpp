#include <iostream>
using namespace std;
int gerarID(){
	static int ID = 0;
	return ID++;
}

int main(){
	string nome;
	
	while(1){
		cout << "digite o nome da pessoa : ";
		cin >> nome;
		cout << "ID gerando pelo usuario " << nome << ": "<< gerarID()<<endl;
	}
	return 0;
}
