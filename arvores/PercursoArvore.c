/*  Nome: Julia Alice Leao
	Data: 2022-07-07
	Projeto: Exercício que insere em uma árvore e testa os três tipos de percursos possíveis.
	-- juliaaliceleao@ufmg  --  */

//bibliotecas
#include <stdio.h>
#include "arvore.h"

//constantes
#define SUCESSO 0

int main(int argc, char ** argv)
{
	//criando uma arvore
	Arv * arvoreesq = arv_cria('b', NULL, NULL);
	Arv * arvoredir = arv_cria('c', NULL, NULL);
	Arv * arvore = arv_cria('a', arvoreesq, arvoredir);
	printf("Pre Ordem:\n");
	arv_imprime_preordem(arvore);
	printf("\nSimetrica:\n");
	arv_imprime_simetrica(arvore);
	printf("\nPos Ordem:\n");
	arv_imprime_posordem(arvore);
//se ocorreu tudo bem, será retornado SUCESSO
	return SUCESSO;
}
