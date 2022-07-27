#define N 500

struct fila
{
	int n;
	int ini;
	float vet[N];
};

struct lista1
{
	int info;
	struct lista1 * prox;
};

typedef struct lista1 Lista1;

struct filal
{
	Lista1 * ini;
	Lista1 * fim;
};
typedef struct fila Fila;
typedef struct filal FilaL;
Fila *fila_cria_vet();
void fila_insere_vet(Fila *f, float v);
float fila_retira_vet(Fila *f);
int fila_vazia_vet(Fila *f);
void fila_libera_vet(Fila *f);

FilaL * fila_cria_l();
void fila_insere_l(FilaL *f, int v);
int fila_retira_l(FilaL * f);
int fila_vazia_l(FilaL *f);
void fila_libera_l(FilaL *f);
Lista1 * fila_busca_l(FilaL *fila, int informacao);