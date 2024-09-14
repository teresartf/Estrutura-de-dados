// matriz quadrática 
// matsim.h

struct matsim{
    int dim;
    float* v;
};

typedef struct matsim MatSim;

MatSim* criar(int n);
float acessar(MatSim* mat, int i, int j);
void atribuir(MatSim* mat, int i, int j, float v);
int dimensao(MatSim* mat);
void listar(MatSim* mat);
void liberar(MatSim* mat);