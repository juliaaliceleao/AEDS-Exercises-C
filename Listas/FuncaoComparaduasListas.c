/*  Nome: Julia Alice Leao
    Data: 2022-04-29
    Projeto: funcao que compara duas listas
    -- juliaaliceleao@ufmg  --  */
    
//bibliotecas
#include <stdio.h>
#include "listas.h"

//constantes
#define SUCESSO 0
#define VERDADEIRO (1==1)
#define FALSO 0
#define bool int

//Função que compara duas listas e retorna um bool se são iguais ou diferentes
bool compara2listas (Lista * listacriada1, Lista * listacriada2)
{
    //Pre verificações
    /*verifica se alguma das listas esta vazia*/
    
    if (listacriada1 == NULL || listacriada2 == NULL)
    {
        return FALSO;   //return falso se as lista estão vazias
    }
    
    Lista * p1;
    Lista * p2 ;
    int tamlista1 = 0;
    int tamlista2 = 0;
    
    //calculando tamanho da lista 1 e 2
    for(p1 = listacriada1; p1 != NULL; p1 = p1->prox)
    {
        tamlista1++;
    }
    for(p2 = listacriada2; p2 != NULL; p2 = p2->prox)
    {
        tamlista2++;
    }
    
    //verifica se o tamanho da lista 1 é igual ao da lista 2
    if(tamlista1 != tamlista2)
    {
        return FALSO;   //return falso se diferem em tamanho
    }
    
    p1 = listacriada1;
    p2 = listacriada2;
    
    for(int i = 0; tamlista1 > i; i++)
    {
        if(p1->info == p2->info)
        {
            p1 = listacriada1->prox;
            p2 = listacriada2->prox;
        }
        else
        {
            return FALSO;
        }
    }
    return VERDADEIRO;
}


int 
main (int argc, char ** argv)
{ 
    //Variaveis
    Lista * listacriada1;
    Lista * listacriada2;
    //dados pelo usuario
    int info, tamlista;

    //chamando funcao que cria listas e guardando o ponteiro da lista criada
    listacriada1 = lst_cria();
    listacriada2 = lst_cria();
    
    //Leitura
    //--preenchendo lista criada 1
    printf("Digite a quantidade de celulas para a lista 1:\n >");
    scanf("%i", &tamlista);
    printf("\nLISTA 1\n");
    for (int i = 0; i <  tamlista; i++)
    {
        printf("Digite um inteiro para a celula %i:", i+1);
        scanf("%i", &info);
        listacriada1 = lst_insere(listacriada1, info);
    }
    printf("Digite a quantidade de celulas para a lista 2:\n >");
    scanf("%i", &tamlista);
    
    //--preenchendo lista criada 2
    printf("\nLISTA 2\n");
    for (int i = 0; i <  tamlista; i++)
    {
        printf("Digite um inteiro para a celula %i:", i+1);
        scanf("%i", &info);
        listacriada2 = lst_insere (listacriada2, info);
    }
    int resultado = compara2listas (listacriada1, listacriada2);
    //imprime resultado
    if(resultado == VERDADEIRO)
    {
        printf("As listas são iguais.");
    }
    else
    {
        printf("As listas são diferentes.");
    }
    //libera a memoria alocada para as duas listas
    lst_libera(listacriada1);
    lst_libera(listacriada2);

    return SUCESSO;
}
