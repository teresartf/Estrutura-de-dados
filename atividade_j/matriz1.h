// matriz.h

typedef struct matriz Matriz;

Matriz* criar1(int m, int n);
void liberar1(Matriz* mat);
float acessar1(Matriz* mat, int i, int j);
void atribuir1(Matriz* mat, int i, int j, float v);
int linhas1(Matriz* mat);
int colunas1(Matriz* mat);
void listar1(Matriz* mat);
Matriz* transposta1(Matriz* mat);
bool eh_simetrica1(Matriz* mat);