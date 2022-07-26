/*  Nome: Julia Alice Leao
	Data: 2022-07-07
	Projeto: Exercício que insere em uma arvore de forma crescente,
	menores que a raiz a esquerda e maiores que a raiz a direita
	-- juliaaliceleao@ufmg  --  */

//bibliotecas
#include <stdio.h>
#include "arvore.h"

//constantes
#define SUCESSO 0
#define QtdElemArvore 10
int main(int argc, char ** argv)
{
	//criando uma arvore
	Arv * arvore = arv_criavazia();
	char VetordeChar[QtdElemArvore] = {'A','D','F','Z','N','U','T','R','E','I'};
	//Adicionando elementos na arvore
	for(int i = 0; i < QtdElemArvore; i++)
	{
    	arvore = InsereCrescente(arvore, VetordeChar[i]);
	}
	//imprimindo na ordem esquerda - raiz - direita
	printf("\nSimetrica:\n");
	arv_imprime_simetrica(arvore);
    //se ocorreu tudo bem, será retornado SUCESSO
    return SUCESSO;
}
