#include "hanoi.h"
static char* opcao = NULL;

int main(){
    srand(time(NULL));
    opcao = "2";

    Stack* torreR; 
    Stack* torreG;
    Stack* torreB;

    Stack* copyR; 
    Stack* copyG;
    Stack* copyB;
    
    int movimentos = 0;
    int status = 0;

    while(opcao[0] != '3'){
        if(opcao[0] == '2'){
            int nivel = menu();
            if(nivel == 1){
                torreR = criarTorreR();
                torreG = criar(MAX);
                torreB = criar(MAX);
                copyR = copiar(torreR);
                copyG = copiar(torreG);
                copyB = copiar(torreB);
                movimentos = 0;
            } else if(nivel == 2){
                torreR = criarTorreR();
                torreG = criarTorreGB();
                torreB = criarTorreGB();
                copyR = copiar(torreR);
                copyG = copiar(torreG);
                copyB = copiar(torreB);
                movimentos = 0;
            } else if(nivel == 3){
                torreR = criarTorreRGB();
                torreG = criarTorreRGB();
                torreB = criarTorreRGB();
                copyR = copiar(torreR);
                copyG = copiar(torreG);
                copyB = copiar(torreB);
                movimentos = 0;
            }
        }
        if(status == 0){
            show(torreR, torreG, torreB, movimentos);
            opcao = menu2();
            
            if(opcao[0] == '1'){
                liberar(torreR);
                torreR = copiar(copyR);

                liberar(torreG);
                torreG = copiar(copyG);

                liberar(torreB);
                torreB = copiar(copyB);

                movimentos = 0;
            } else if( opcao[0] == '2'){
                liberar(torreR);
                liberar(torreG);
                liberar(torreB);
            } else{
                atualizarTorres(torreR, torreG, torreB, opcao, &movimentos);
                status = status_jogo(torreR, torreG, torreB, movimentos);
            }
        }

        if(status == 1){
            printf("\n1- Reiniciar Jogo; 2- Novo Jogo; 3- SAIR");
            printf("\nDigite sua opção: ");
            scanf("%s", opcao);

            if(opcao[0] == '1'){
                liberar(torreR);
                torreR = copiar(copyR);

                liberar(torreG);
                torreG = copiar(copyG);

                liberar(torreB);
                torreB = copiar(copyB);

                status = 0;
                movimentos = 0;
            } else if( opcao[0] == '2'){
                liberar(torreR);
                liberar(torreG);
                liberar(torreB);
            } 
        }
    }

    liberar(torreR);
    liberar(torreG);
    liberar(torreB);
    liberar(copyR);
    liberar(copyG);
    liberar(copyB);
    free(opcao);
    return 0;
}