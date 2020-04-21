#include <iostream>
#include <vector>
using namespace std;
class Pontos{
	public:
		int x,y;
		Pontos(int x,int y){
			this->x = x;
			this->y = y;
		}
};

int main(){
	vector<Pontos*> vet;
	vector<Pontos*>::iterator it;
	Pontos *p1 = new Pontos(10,10);
	Pontos *p2 = new Pontos(20,20);
	
	vet.push_back(p1);
	vet.push_back(p2);
	
	for (it = vet.begin(); it < vet.end(); it++)
	{
		cout << (*it)->x <<" " << (*it)->y <<endl;
	}
	
	return 0;
}
