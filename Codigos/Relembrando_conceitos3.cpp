#include <iostream>
using namespace std;
class Pai1{
	public:
	void foo1(){
		cout << "oi sou o pai 1";
	}		
};

class Pai2{
	public:
	void foo2(){
		cout << "oi sou o pai 2";
	}		
};

class Filha : public Pai1,Pai2{
	
	
};

int main(){
	Filha f;
	f.Pai1::foo1();
	f.foo2();
return 0;
}
