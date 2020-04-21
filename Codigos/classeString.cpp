#include <iostream>
#include <string>

using namespace std;

int main(){
	
	
	string str = "marcos";
	cout << str.size()<<endl;
	cout << str.length()<<endl;
	cout << str.at(1) << endl;//escolhe o elemento
	cout << str.at(str.size()-1) << endl;
	cout<<str.back();//ultimo elemento
	cout<<str.front();//primeiro elemento
	
	str.append(" casais");
	cout << str;
 return 0;
}
