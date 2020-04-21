#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    for (size_t i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " " <<endl;
    }
    
    vector<int>::iterator it = v1.begin();
    cout << *it <<endl;

    for(it;  it != v1.end();it++){
        cout << *it << endl;
    }

    //verificar se o vetor esta vazio
    cout << "################";
    vector<int> v2;
    v2.empty() ? cout<< "vetor vazio" : cout << "vetor nao vazio"<<endl; 
    cout<<endl;
    v2.push_back(40);
   v2.empty() ? cout<< "vetor vazio" : cout << "vetor nao vazio"<<endl; 

   //funcao para remover;
    cout << endl;
   while(!v1.empty()){
       v1.pop_back();
   }    
   if(v1.empty()){
       cout << "tudo limpo";
   }
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    
    cout << v1.at(1);
     
return 0;
}