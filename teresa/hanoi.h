#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 7

typedef struct node{
    char value;
    struct node* next;
}Node;

typedef struct stack{
    Node* top;
    int max_size;
    int actual_size;
}Stack;

Stack* criar(int max_size);
int is_empty(Stack* stack);
int is_full(Stack* stack);
int can_pop(Stack* stack);
int can_push(Stack* stack);
void push(Stack* stack, char value);
int pop(Stack* stack);
void liberar(Stack* stack);
void show(Stack* torreR, Stack* torreG, Stack* torreB, int movimentos);
int menu();
char* menu2();
char menu3();
int validar(const char* op);
int validar3(char op);
Stack* criarTorreR();
char traduzir(int numero);
Stack* criarTorreGB();
Stack* criarTorreRB();
Stack* criarTorreG();
Stack* copiar(Stack* torre);
void atualizarTorres(Stack* torreR, Stack* torreG, Stack* torreB, char* opcao, int* movimentos);
int status_jogo(Stack* torreR, Stack* torreG, Stack* torreB, int movimentos);