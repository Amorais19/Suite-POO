#include "forca.h"

std::string forca::Sortear(){
    int n=rand()%TAM;
    return palavras[n];
}
std::string forca::montarP2(std::string p1){
std::string p2="";
    for(int i=0;i<p1.length();i++){
        p2+='_';
    }
    return p2;
}
std::string forca::verificarLetra(std::string p1,std::string p2,char L,bool* achei){
    *achei=false;
    for(int i=0;i<p1.length();i++){
        if(p1[i]==L){
            p2[i]=L;
            *achei=true;
        }
    }
    return p2;
}
bool forca::verificaFimJogo(std::string p2){
for(int i=0;i<p2.length();i++){
    if(p2[i]=='_'){
        return false;
    }
}
return true;
}
