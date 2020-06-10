#ifndef AVIAO_H_INCLUDED
#define AVIAO_H_INCLUDED
#include "cor.h"
class Aviao{
    public:
        int vel = 0;
        int velmax;
        std::string tipo;
        Aviao(int tp);        
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


#endif