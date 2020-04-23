#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector <int> v;
	v.push_back(20); // coloca o elemento no final 
	v.push_back(30); 
	v.push_back(40);
	
	int tam = v.size();
	
	for (int i = 0; i < tam; i++)
	{
		cout << v[i] << " " << endl;
	}
	
	vector<int>::iterator it = v.begin();
	cout << *it <<endl;
return 0;
}
