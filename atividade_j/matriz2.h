// matriz.h

typedef struct matriz Matriz;

Matriz* criar2(int m, int n);
void liberar2(Matriz* mat);
float acessar2(Matriz* mat, int i, int j);
void atribuir2(Matriz* mat, int i, int j, float v);
int linhas2(Matriz* mat);
int colunas2(Matriz* mat);
void listar2(Matriz* mat);
Matriz* transposta2(Matriz* mat);
bool eh_simetrica2(Matriz* mat);