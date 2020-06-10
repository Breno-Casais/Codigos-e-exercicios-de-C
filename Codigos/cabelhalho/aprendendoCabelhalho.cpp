#include <iostream>
#include "aviao.h"
using namespace std;

int main(){
Aviao * a1 = new Aviao(2);
cout << a1 -> tipo << endl;
cout << a1 -> velmax;

    return 0;
}