#include <iostream>
#include <map>

using namespace std;

int main(){
	
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
