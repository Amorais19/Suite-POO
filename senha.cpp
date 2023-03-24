#include "senha.h"

void senha::GerarSenha(){
    for(int i=0;i<4;i++){
        SenhaGerada[i]=Cores[rand()%4];
    }
};
int senha::VerificarAcertos(){
    int total=0;
    for(int i=0;i<4;i++){
        if(Palpites[i]==SenhaGerada[i]){
            total++;
        }
    }
    return total;
};
