#include <iostream>
using namespace std;
namespace ns1{
	int num = 42;
	
	class A{
		public :
			void imprimir(){
				cout << "ola, sou a class A do namespace ns1"<<endl;
			}
	};
}

namespace ns2{
	int num = 50;
	class A{
		public :
			void imprimir(){
				cout << "ola, sou a class A do namespace ns2"<<endl;
			}
	};
}

int main(){
	ns1::A ns1A;
	ns2::A ns2A;

	ns1A.imprimir();
	ns2A.imprimir();
	return 0;
}

