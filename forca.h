#include <iostream>

class forca{
public:
    const static int TAM = 20;
    std::string palavras[TAM]={"numero","hoje","quatro","musica","ensinar","jogar","acordar","estudar","gostar","contar",
"maiden","metal","volei","programar","oitenta","rede","guitarra","ironia","universo","pessoa"};
    std::string Sortear();
    std::string montarP2( std :: string );
    std::string verificarLetra(std::string,std::string,char,bool*);
    bool verificaFimJogo(std::string);
};
