/*  Nome: Julia Alice Leao
    Data: 2022-07-09
    Projeto: Considere uma árvore binária, faça uma função que monte um
histograma de ocorrência dos caracteres que aparecem na árvore.
    -- juliaaliceleao@ufmg  --  */

//bibliotecas
#include <stdio.h>
#include "arvore.h"

//constantes
#define SUCESSO 0
#define QtdElemArvore 10

//Funcoes
/*Função 1
conta quantas vezes um char Procurado aparece em uma arvore
Retorno: quantidade de vezes que o char aparece
Parametro: char procurado, endereço de uma variavel do tipo Arv e
contador de quantas vezes apareceu na arvore*/
int ContaOcorrencias(char Procurado, Arv * arvore, int contador)
{
    if(arvore==NULL)
    {
        return contador;
    }
    if(Procurado == arvore->info)
    {
        contador+=1;
    }
    ContaOcorrencias(Procurado, arvore->esq, contador);
    ContaOcorrencias(Procurado, arvore->dir, contador);
}
//Função/Procedimento 2
/*Imprime a frequencia de vezes que cada caracter contido em uma arvore aparece na mesma
Retorno: void
Parametro: endereço de uma variavel do tipo Arv, um vetor para armazenar caracteres 
ja existentes no histograma e nao repeti-los e j para guardar a quantidade de caracteres 
ja existentes e compara-los posteriormente*/
void arv_historigramadeocorrencias(Arv * arvore,char * JaExiste,int j)
{
    if(!arv_vazia(arvore))
    {
        int cancela = 0;
        //confere se a letra ja consta
        for(int i = 0; i < j; i++)
        {
            if(arvore->info==JaExiste[i])
            {
                cancela=1;
            }
        }
        if(cancela==0)
        {
            int contador = ContaOcorrencias(arvore->info,arvore,0);
            printf("%c |",arvore->info);
            for(int i = 0; i < contador; i++)
            {
                printf("X");
            }
            printf("\n");
            JaExiste[j]=arvore->info;
            j++;
        }
        arv_historigramadeocorrencias(arvore->esq,JaExiste, j);
        arv_historigramadeocorrencias(arvore->dir,JaExiste, j);
    }
}
int main(int argc, char ** argv)
{
    //variaveis
    int contador = 0;
    char VetordeChar[QtdElemArvore] = {'X','Z','Z','U','Z','R','Z','J','F','C'};
    
    //criando uma arvore
    Arv * arvore = arv_criavazia();
    //Inserção: Adicionando elementos na arvore
    for(int i = 0; i < QtdElemArvore; i++)
    {    arvore = InsereCrescente(arvore, VetordeChar[i]); }
    
    //Criando um vetor para armazenar as letras da arvore e nao repeti-las
    char JaExiste[arv_altura(arvore)];
    
    //Chamando procedimento que imprime um histograma
    arv_historigramadeocorrencias(arvore,JaExiste,0);
    
    //liberando arvore
    arv_libera(arvore);
    //se ocorreu tudo bem, será retornado SUCESSO
    return SUCESSO;
}
