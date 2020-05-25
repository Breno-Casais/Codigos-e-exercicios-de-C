#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	vector <string> nome;
	vector <string>::iterator it;
	
	map<int, vector<string>> teste;
	
	nome.push_back("breno");
	nome.push_back("fernado");
	
	for (int i = 0; i < 3; i++)
	{
		
	}
	
	
	map<int,string> mapa = {
		{1,"pedro"},
		{2,"maria"},
		{3,"joao" }
	};
	
	cout << mapa[1]<<endl;
	cout << mapa[2]<<endl;
	cout << mapa[3]<<endl;
	
	//alterando o valor associado a uma chave
	mapa.at(1) = "carol";
	cout << mapa[1]<<endl;
	//verificando se o mapa esta vazio
	if(mapa.empty())
		cout<<"mapa nao vazio"<<endl;
	else
		cout << "ocupado";
	//mapa.clear();
	
	
	if(mapa.count(1) > 0)
		cout << "è elemento do mapa";
	else
		cout << "nao e elemento do mapa";
	
	map<int ,string>::iterator it;

	for (it = mapa.begin(); it != mapa.end(); it++)
	{
		
		cout << " A chave " << it->first << " => " << it->second <<endl ;
	}

	return 0;
}
