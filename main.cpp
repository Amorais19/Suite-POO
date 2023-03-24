#include "forca.h"
#include "velha.h"
#include "senha.h"

using namespace std;

int main (){
    forca f;
    int op , jogadas;
    string p1,p2,letras ;
    char L;
    bool achei,acertou;
    velha v;
    char V[3][3];
    int i,j,cont,k;
    bool J1,J2,linha,coluna,diagP,diagS;
    char continua;
    srand(time(NULL));
    senha s;
    int acertos;
    do{
        system("clear");
        cout<<"1-Jogo da Forca"<<endl ;
        cout<<"2-Jogo da Velha"<<endl;
        cout<<"3-Jogo da Senha"<<endl;
        cout<<"4-Sair"<<endl;
        cin>>op;
        switch (op){
            case 1:
                p1=f.Sortear();
                letras="";
                jogadas=0;
                p2=f.montarP2(p1);
                acertou=false;
                do{
                    system("clear");
                    cout<<"Palavra: "<<p2<<endl;
                    cout<<"Letras : "<<letras<<endl;
                    cout<<"Jogadas: "<<jogadas<<endl;
                    cout<<"Informe uma letra : ";
                    cin>>L;
                    p2=f.verificarLetra(p1,p2,L,&achei);
                    letras+=L;
                    if(!achei){
                        jogadas++;
                    }
                    acertou=f.verificaFimJogo(p2);
                }
                while(jogadas<6 && !acertou);
                    if(acertou){
                    cout<<"Parabéns!!Acertou a palavra: "<<p2<<endl;
                    }
                    else{
                    cout<<"Errou. Que pena!!A palavra era: "<<p1<<endl;
                }
                break;
            case 2:
                jogadas=0;
                J1=false;
                J2=false;
                v.inicializar(V);
                do{
                    v.desenhaMatriz(V);
                    do{
                        cout<<"Jogador 1,faça sua jogada informando linha e coluna: ";
                        cin>>i>>j;
                    }while(V[i][j]!=NULL);
                        V[i][j]='X';
                        J1=v.verificaVencedor(V,'X',i,j);
                        if(J1)
                            break;
                        jogadas++;
                        if(jogadas<9){
                            v.desenhaMatriz(V);
                            do{
                                cout<<"Jogador 2,faça sua jogada informando linha e coluna: ";
                                cin>>i>>j;
                            }while(V[i][j]!=NULL);
                                V[i][j]='O';
                                J2=v.verificaVencedor(V,'O',i,j);
                                if(J2)
                                    break;
                                jogadas++;
                        }
                }while((jogadas<9) && (!J1) && (!J2));
                    if(J1){
                        cout<<"Jogador 1 venceu!";
                        }
                    else if(J2){
                        cout<<"Jogador 2 venceu!";
                    }
                    else{
                        cout<<"Empatou!";
                    }
                break;
            case 3:
                system("clear");
                s.GerarSenha();
                jogadas=0;
                acertou=false;
                do{
                    cout<<"Informe seu palpite: v-vermelho | a-azul | p-preto | b-branco ";
                    cout<<"jogada "<< jogadas<<": ";
                    for(i=0;i<4;i++){
                        cin>>s.Palpites[i];
                    }
                    acertos=s.VerificarAcertos();
                    if(acertos==4){
                        acertou=true;
                    }
                    else{
                        jogadas++;
                        cout<<acertos<<" acertos"<<endl;
                    }
                }while(jogadas<=10 && !acertou);
                    if(acertou){
                        cout<<"Parabéns, você acertou.";
                    }
                    else{
                        cout<<"Você errou! A senha era: ";
                        for(i=0;i<4;i++){
                            cout<<s.SenhaGerada[i]<<" ";
                        }
                    }
            case 4:
                cout<<"Adeus!"<<endl;
                break;
            default:
            cout<<"Opção inválida!!"<<endl;
        }
        cin.ignore().get();
    }
    while( op != 4) ;
    return 0;
}
