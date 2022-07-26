/*  Nome: Julia Alice Leao
    Data: 2022-07-08
    Projeto: Dada uma árvore binária, faça uma função para contar o número de
    folhas, o número de nós com um filho e o número de nós com dois filhos.
    -- juliaaliceleao@ufmg  --  */

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

//constantes
#define SUCESSO 0
#define QtdElemArvore 10

//Funcoes
/*Função 1
conta o número de folhas na arvore, o número de nós com um filho e o número de nós com 
dois filhos 
Retorno: endereço de um vetor onde estão contidos esses tres valores de retorno
Parametro: Endereço do vetor e Endereço de uma variavel da estrutura Arv.*/
int * arv_contafolhas(Arv * arvore, int * contador)
{
    if(!arv_vazia(arvore))
    { 
        if(arvore->esq == NULL && arvore->dir == NULL)
            contador[0]++;//NUMERO DE FOLHAS
        else
        if(arvore->esq == NULL || arvore->dir == NULL)
            contador[1]++;//NUMERO DE NOS COM APENAS UM FILHO
        else
        if(arvore->dir != NULL && arvore->dir != NULL)
            contador[2]++;//NUMERO DE NOS COM DOIS FILHOS
        
        arv_contafolhas(arvore->dir, contador);
        arv_contafolhas(arvore->esq, contador);
    }
    return contador;
}

int main(int argc, char ** argv)
{
    //variaveis
    char VetordeChar[QtdElemArvore] = {'X','Z','F','Z','N','U','T','R','E','A'};
    int * contador;
   
    //criando uma arvore
    Arv * arvore = arv_criavazia();
    //Inserção: Adicionando elementos na arvore
    for(int i = 0; i < QtdElemArvore; i++)
    {    arvore = InsereCrescente(arvore, VetordeChar[i]); }
    //alocando espaço para armazenar um vetor de inteiro de 3 elementos
    contador = (int *) malloc(sizeof(int) * 3);
    
    //Impressão
    //imprimindo na ordem esquerda - raiz - direita
    printf("\nSimetrica:\n");
    arv_imprime_simetrica(arvore);
    
    //Chamando a funcao que devolve informações sobre a arvore e retorna o endereço de um vetor com as informações
    contador = arv_contafolhas(arvore, contador);
    //Exibindo resultado
    printf("\nNumero de Folhas: %i", contador[0]);
    printf("\nNumero de Nos c/ um filho: %i", contador[1]);
    printf("\nNumero de Nos c/ dois filhos: %i", contador[2]);

    //liberando arvore
    arv_libera(arvore);
    //se ocorreu tudo bem, será retornado SUCESSO
    return SUCESSO;
}
