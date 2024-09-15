
#include "hanoi.h"
static char* opcao = NULL;
static char op;

int main(){
    srand(time(NULL));
    opcao = "2";
    int nivel;
    int recomeco = 1;

    Stack* torreR; 
    Stack* torreG;
    Stack* torreB;

    Stack* copyR; 
    Stack* copyG;
    Stack* copyB;
    
    int movimentos = 0;
    int status = 0;

    while(status == 0){
        if(recomeco == 1){
            nivel = menu();
            switch (nivel)
            {
            case 1:
                torreR = criarTorreR();
                torreG = criar(MAX);
                torreB = criar(MAX);
                copyR = copiar(torreR);
                copyG = copiar(torreG);
                copyB = copiar(torreB);
                movimentos = 0;
                recomeco = 0;
                break;
            
            case 2:                
                torreR = criarTorreR();
                torreG = criarTorreGB();
                torreB = criarTorreGB();
                copyR = copiar(torreR);
                copyG = copiar(torreG);
                copyB = copiar(torreB);
                movimentos = 0;
                recomeco = 0;
                break;

            case 3:
                torreR = criarTorreRB();
                printf("\ncriada rb");
                torreG = criarTorreG();
                printf("\ncriada g");
                torreB = criarTorreRB();
                copyR = copiar(torreR);
                copyG = copiar(torreG);
                copyB = copiar(torreB);
                movimentos = 0;
                recomeco = 0;
                break;
            }
        }

        show(torreR, torreG, torreB, movimentos);
        opcao = menu2();
        
        if(status == 0){
            if(opcao[0] == '3'){
                exit(1);
            }
            //1 reinicia
            else if(opcao[0] == '1'){
                if(nivel == 1){
                    liberar(torreR);
                    torreR = copiar(copyR);
                    liberar(torreG);
                    liberar(torreB);
                    torreG = criar(MAX);
                    torreB = criar(MAX);
                    movimentos = 0;
                    recomeco = 0;
                }
                else if(nivel == 2){
                    liberar(torreB);
                    torreR = copiar(copyR);
                    liberar(torreG);
                    torreG = copiar(copyG);
                    liberar(torreB);
                    torreB = copiar(copyB);
                    movimentos = 0;   
                    recomeco = 0;                 
                }
                else if(nivel == 3){
                    liberar(torreR);
                    torreR = copiar(copyR);
                    liberar(torreG);
                    torreG = copiar(copyG);
                    liberar(torreB);
                    torreB = copiar(copyB);
                    movimentos = 0;  
                    recomeco = 0;                  
                }
            }
            else if(opcao[0] == '2'){
                recomeco = 1;
            }
            else{
                recomeco = 0;
                atualizarTorres(torreR, torreG, torreB, opcao, &movimentos);
                status = status_jogo(torreR, torreG, torreB, movimentos);
            }
        }

        if(status == 1){
            op = menu3();

            if(op == '1'){
                if(nivel == 1){
                    liberar(torreR);
                    torreR = copiar(copyR);
                    liberar(torreG);
                    liberar(torreB);
                    torreG = criar(MAX);
                    torreB = criar(MAX);
                    movimentos = 0;
                    status = 0;
                    recomeco = 0;
                }else if(nivel == 2){
                    liberar(torreR);
                    torreR = copiar(copyR);
                    liberar(copyG);
                    torreG = copiar(copyG);
                    liberar(torreB);
                    torreB = copiar(copyB);
                    movimentos = 0;
                    status = 0;     
                    recomeco = 0;               
                }
                else if(nivel == 3){
                    liberar(torreR);
                    torreR = copiar(copyR);
                    liberar(torreG);
                    torreG = copiar(copyG);
                    liberar(torreB);
                    torreB = copiar(copyB);
                    movimentos = 0;
                    status = 0;     
                    recomeco = 0;               
                }
            } else if( op == '2'){
                recomeco = 1;
                status = 0;
            } else if(op == '3'){
                exit(1);
            }
        }
    }

    liberar(copyR);
    liberar(torreR);
    liberar(torreG);
    liberar(torreB);
    return 0;
}
