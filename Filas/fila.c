#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "string.h"

static int incr(int i)
{
	return (i+1)%N;
}
Fila * fila_cria_vet()
{
	Fila *f = (Fila *) malloc(sizeof(Fila));
	f->n = 0;
	f->ini = 0;
	return f;
}
void fila_insere_vet(Fila *f, float v)
{
	int fim;
	if(f->n == N)
	{
		printf("Capacidade da fila estourou\n");
		exit(1);
	}
	fim = (f->ini + f->n)%N;
	f->vet[fim] = v;
	f->n++;
}

float fila_retira_vet(Fila *f){
	float v;
	if(fila_vazia_vet(f))
	{
		printf("Fila vazia!\n");
		exit(1);
	}
	v=f->vet[f->ini];
	f->ini = (f->ini + 1) % N;
	f->n--;
	return v;
}

int fila_vazia_vet(Fila *f)
{
	return (f->n == 0);
}

void fila_libera_vet(Fila *f){
	free(f);
}
// Lista encadeada
FilaL *fila_cria_l(){
	FilaL *f = (FilaL *) malloc(sizeof(FilaL));
	f->ini = f->fim = NULL;
	return f;
}
void fila_insere_l(FilaL * f,int v)
{
	Lista1 * n = (Lista1 *) malloc(sizeof(Lista1));
	int i;
	n->info=v;
	n->prox = NULL;
	if(f->fim != NULL) f->fim->prox = n;
	else f->ini = n;
	f->fim = n;
}
int fila_retira_l(FilaL *f){
	Lista1 *t;
	int v;
	if(fila_vazia_l(f))
	{
		printf("Fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->info;
	f->ini = t->prox;
	if(f->ini==NULL) f->fim = NULL;
	free(t);
	return v;
}

int fila_vazia_l(FilaL *f)
{
	return (f->ini == NULL);
}

void fila_libera_l(FilaL *f)
{
	Lista1 *q = f->ini;
	while(q!=NULL){
		Lista1 *t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

Lista1 * fila_busca_l(FilaL *fila, int informacao){
	Lista1 * q;
	for(q=fila->ini; q!=NULL; q=q->prox){
		if(informacao==q->info){
			return q;
		}
	}
	return NULL;
}
// Funções de impressão
void fila_imprime_vet(Fila *f){
	int i;
	for(i=0;i<f->n; i++) printf("%f \n", f->vet[(f->ini+i)%N]);
}