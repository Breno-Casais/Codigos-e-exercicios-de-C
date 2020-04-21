#include <iostream>
using namespace std;
class Base{
	private:
		int n;
	protected:
		int n1,n2;
	public:
		int n3,n4;

		Base(){
			n1 = 1;
			n2 = 2;
			n3 = 3;
			n4 = 4;	
		}
		
};

class Subliclass : public Base  {
	public :
		void foo(){
			cout << "subclasse1" << endl;
			//cout << n <<endl;
			cout << n1 <<endl;
			cout << n2 <<endl;
			cout << n3 <<endl;
			cout << n4 <<endl;
		}
	
};
class Subliclass2 : private Base{
	public:
		void foo(){
			cout << "subclasse2" << endl;
			//cout << n <<endl;
			cout << n1 <<endl;
			cout << n2 <<endl;
			cout << n3 <<endl;
			cout << n4 <<endl;
		}
	
};
int main(){
	Subliclass s1;
	Subliclass2 s2;
	
	s1.foo();
	s2.foo();
	
	
return 0;
}
