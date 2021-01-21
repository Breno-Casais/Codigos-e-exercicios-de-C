#ifndef AVIAO_H_INCLUDED
#define AVIAO_H_INCLUDED
#include "cor.h"
using namespace std;

class Aviao{
    public:
        int vel = 0;
        int velmax;
        std::string tipo;
        Aviao(int tp);        
       virtual void mostrar(){
           cout << this -> velmax;
        }
};

Aviao::Aviao(int tp){
    if(tp == 1){
        this -> tipo = "Jato";
        this -> velmax = 200; 
        COR a1(8);
        std:: cout << a1.rosa;

    }
    if(tp == 2){
        this -> tipo = "Monomotor";
        this -> velmax = 300;         
    }
}

class Motor : Aviao{
    private : 
        string marca;
    public:
        Motor(int tp, string marca) : Aviao(tp){
                this->marca = marca;
        }
        void mostrar(){
            Aviao::mostrar();
            cout << marca;
        }
};


#endif