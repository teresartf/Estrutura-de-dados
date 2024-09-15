#include "hanoi.h"

Stack* criar(int max_size){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    
    stack->top = NULL;
    stack->max_size = max_size;
    stack->actual_size = 0;

    return stack;
}

int is_empty(Stack* stack){
    return stack->top == NULL;
}

int can_pop(Stack* stack){
    return (!is_empty(stack));
}

int is_full(Stack* stack){
    return stack->actual_size == stack->max_size;
}

int can_push(Stack* stack){
    return (!is_full(stack));
}

void push(Stack* stack, char value){
    if(!can_push(stack)){
        printf("\nCapacidade da pilha estourou!");
        return;
    }

    //cria nó
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = stack->top;
    stack->top = node;
    stack->actual_size++;
}

int pop(Stack* stack){
    if(!can_pop(stack)){
        printf("\nPilha vazia!");
        return -1;
    }

    Node* node = stack->top;
    float v = node->value;

    stack->top = stack->top->next;
    stack->actual_size--;

    free(node);
    return v;
}

void liberar(Stack* stack){
    Node* node = stack->top;
    while (node!=NULL) {
        Node* temp = node->next;
        free(node);
        node = temp;
    }

    free(stack);
}

void show(Stack* torreR, Stack* torreG, Stack* torreB, int movimentos){
    printf("\n\n             Movimentos efetuados: %d\n", movimentos);
    printf("\n            R            G           B  \n\n");

    char arrayR[MAX] = {' '}, arrayG[MAX] = {' '}, arrayB[MAX] = {' '};

    Node* noder = torreR->top;
    Node* nodeg = torreG->top;
    Node* nodeb = torreB->top;

    int i;
    int r = 0, g = 0, b = 0;

    for(i = 0; i < MAX && noder != NULL; i++){
        arrayR[i] = noder->value;
        r++;

        noder = noder->next;
    }

    for(i = 0; i < MAX && nodeg != NULL; i++){
        arrayG[i] = nodeg->value;
        g++;

        nodeg = nodeg->next;
    }

    for(i = 0; i < MAX && nodeb != NULL; i++){
        arrayB[i] = nodeb->value;
        b++;

        nodeb = nodeb->next;
    }

    for(i = 0; i < MAX; i++){
        char letra1, letra2, letra3;
        if(i<MAX - r){
            letra1 = ' ';
        }
        else {
            letra1 = arrayR[i - (MAX - r)];
        }

        if(i<MAX - g){
            letra2 = ' ';
        }
        else {
            letra2 = arrayG[i - (MAX - g)];
        }

        if(i<MAX - b){
            letra3 = ' ';
        }
        else {
            letra3 = arrayB[i - (MAX - b)];
        }

        printf("          | %c |        | %c |       | %c |\n", letra1, letra2, letra3);
    }

    printf("\n");
}

int menu(){
    printf("\nMENU:");
    printf("Escolha o nível:\n");
    printf("1- Fácil;");
    printf("2- Médio;");
    printf("3- Difícil;");

    int op;
    printf("\nDigite sua opção: ");
    scanf("%d", &op);

    while(op != 1 && op != 2 && op != 3){
        printf("\nOpção inválida!");
        printf("\nNova opção: ");
        scanf("%d", &op);
    }

    return op;
}

char* menu2(){
    printf("\n1- Reiniciar Jogo; 2- Novo Jogo; 3- SAIR");
    printf("\n\nEscolha um movimento: \nRG - RB - GB - GR - BR - BG");

    char* op = (char*)malloc(2* sizeof(char));
    printf("\nOpção: ");
    scanf("%s", op);

    while(!validar(op)){
        printf("\nOpção inválida!");
        printf("\nNova opção: ");
        scanf("%s", op);
    }

    return op;
}

int validar(char* op){
    if(strlen(op) == 1){
        if(op[0] == '1' || op[0] == '2' || op[0] == '3'){
            return 1;
        }
    } else if(strlen(op) == 2){
       if(op[0] == 'R' && op[1] == 'G'){
        return 1;
       } else if(op[0] == 'R' && op[1] == 'B'){
        return 1;
       } else if(op[0] == 'G' && op[1] == 'B'){
        return 1;
       } else if(op[0] == 'G' && op[1] == 'R'){
        return 1;
       } else if(op[0] == 'B' && op[1] == 'R'){
        return 1;
       } else if(op[0] == 'B' && op[1] == 'G'){
        return 1;
       }
    }

    return 0;
}

   

Stack* criarTorreR(){
    Stack* torreR = criar(MAX);
    int max = 2, min = 0;
    int letraR, letraG, letraB;


    for(int i = 0; i < MAX; i++){
        int numero = rand() % (max - min + 1) + min;

        if(numero == 0) {
            letraR++;
        }else if(numero == 1) {
            letraG++;
        }else if(numero == 2) {
            letraB++;
        }

        char letra = traduzir(numero);
        push(torreR, letra);
    }

    if(letraR != 2 && letraG != 2 && letraB != 2){
        torreR = criarTorreR();
    }

    return torreR;
}

char traduzir(int numero){
    if(numero == 0){
        return 'R';
    } else if(numero == 1){
        return 'G';
    } else {
        return 'B';
    }
}

Stack* criarTorreGB(){
    Stack* torre = criar(MAX);
    int max = 2, min = 0;
    int letraR, letraG, letraB;


    for(int i = 0; i < MAX - 5; i++){
        int numero = rand() % (max - min + 1) + min;

        if(numero == 0) {
            letraR++;
        }else if(numero == 1) {
            letraG++;
        }else if(numero == 2) {
            letraB++;
        }

        char letra = traduzir(numero);
        push(torre, letra);
    }

    if(letraR > 2 || letraG > 2 || letraB > 2){
        torre = criarTorreGB();
    }

    return torre;
}

Stack* criarTorreRGB(){
    Stack* torre = criar(MAX);
    int max = 2, min = 0;
    int letraR, letraG, letraB;


    for(int i = 0; i < MAX - 2; i++){
        int numero = rand() % (max - min + 1) + min;

        if(numero == 0) {
            letraR++;
        }else if(numero == 1) {
            letraG++;
        }else if(numero == 2) {
            letraB++;
        }

        char letra = traduzir(numero);
        push(torre, letra);
    }

    if(((letraR != 2 || letraG != 2) && letraB == 1) ||
        ((letraR != 2 || letraB != 2) && letraG == 1) ||
        ((letraB != 2 || letraG != 2) && letraR == 1)
    ){
        torre = criarTorreRGB();
    }

    return torre;
}

Stack* copiar(Stack* torre){
    Stack* copia = criar(MAX);
    Node* no = torre->top;
    
    while(no != NULL){
        push(copia, no->value);
        no = no->next;
    }

    return copia;
}

void atualizarTorres(Stack* torreR, Stack* torreG, Stack* torreB, char* opcao, int* movimentos){
    if(opcao[0] == 'R' && opcao[1] == 'G'){
        push(torreG, torreR->top->value);
        pop(torreR);
    } else if(opcao[0] == 'R' && opcao[1] == 'B'){
        push(torreB, torreR->top->value);
        pop(torreR);
    } else if(opcao[0] == 'G' && opcao[1] == 'R'){
        push(torreR, torreG->top->value);
        pop(torreG);
    } else if(opcao[0] == 'G' && opcao[1] == 'B'){
        push(torreB, torreG->top->value);
        pop(torreG);
    } else if(opcao[0] == 'B' && opcao[1] == 'R'){
        push(torreR, torreB->top->value);
        pop(torreB);
    } else if(opcao[0] == 'B' && opcao[1] == 'G'){
        push(torreG, torreB->top->value);
        pop(torreB);
    }

    (*movimentos)++;
}

int status_jogo(Stack* torreR, Stack* torreG, Stack* torreB, int movimentos){
    char arrayR[MAX] = {' '}, arrayG[MAX] = {' '}, arrayB[MAX] = {' '};

    Node* noder = torreR->top;
    Node* nodeg = torreG->top;
    Node* nodeb = torreB->top;

    int i;
    int r = 0, g = 0, b = 0;

    for(i = 0; i < MAX && noder != NULL; i++){
        arrayR[i] = noder->value;
        r++;

        noder = noder->next;
    }

    for(i = 0; i < MAX && nodeg != NULL; i++){
        arrayG[i] = nodeg->value;
        g++;

        nodeg = nodeg->next;
    }

    for(i = 0; i < MAX && nodeb != NULL; i++){
        arrayB[i] = nodeb->value;
        b++;

        nodeb = nodeb->next;
    }

    for(i = 0; i < MAX; i++){
        char letra1, letra2, letra3;
        if(i<MAX - r){
            letra1 = ' ';
        }
        else {
            letra1 = arrayR[i - (MAX - r)];
        }

        if(i<MAX - g){
            letra2 = ' ';
        }
        else {
            letra2 = arrayG[i - (MAX - g)];
        }

        if(i<MAX - b){
            letra3 = ' ';
        }
        else {
            letra3 = arrayB[i - (MAX - b)];
        }

        if (!(letra1 == 'R' || letra1 == ' ') || !(letra2 == 'G' || letra2 == ' ') || !(letra3 == 'B' || letra3 == ' ')) {
            show(torreR, torreG, torreB, movimentos);
            printf("\n");
            return 0;
        }
    }

    show(torreR, torreG, torreB, movimentos);
    printf("\n\n Você venceu! Com %d movimentos!\n", movimentos); 
    return 1;

}