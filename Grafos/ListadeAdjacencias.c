/**
 * @file main2.c
 * @Name Julia Alice Leao
 * @Date 2022-07-20
 * @Project Lista de Adjacencias - Grafo Nao-Orientado
 * -- juliaaliceleao@ufmg  --
*/

//Inclusoes
#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

//Constantes
#define SUCESSO 0
#define ERRO 1

//inicio do main
int 
main(int argv, char ** argc)
{
    //Variaveis
    int NumVertices; //Armazenando o numero de vertices
    int resposta = 0; 
    
    //Criacao do Grafos
    //--Leitura de NumVertices
    printf("Num. Vertices: ");
    scanf("%i", &NumVertices);
    if(!NumVertices) //se NumVertices for == 0, encerre aqui
        return ERRO;
    
    struct GrafoLista * Grafo =  GrafoLista_cria();
    
    //--Imprimindo um grafo sem arestas com a funcao ASCIIGrafo
    ImprimeGrafo_Vertice(NumVertices);
    
    //--Inserindo os Vertices
    Grafo = GrafoLista_InsereVertices(NumVertices);
    //Inserindo as Arestas
    for(int i = 0; i < NumVertices; i++)
    {
        for(int j = 0; j < NumVertices; j++)
        {
            //Buscando caso o elemento ja tenha sido adicionado na lista
            int resultado = BuscaGrafo_ListaAdjacencias(Grafo, i, j);
            resultado += BuscaGrafo_ListaAdjacencias(Grafo, j, i);
            if(resultado == 0)
            {
                printf("\nO Vertice %i se liga c/ o Vertice %i \n %i--->%i ? \n",Grafo[i].info,Grafo[j].info,i+1,j+1);
                printf("\t1-Sim\n\t2-Nao\n");
                scanf("%i", &resposta);
                if(resposta == 1)
                {
                    /*insercao do elemento na lista de adjacencias 
                    dos dois vertice pois o grafo nao e orientado*/
                    InsereGrafo_ListaAdjacencias(Grafo, i, j);
                    InsereGrafo_ListaAdjacencias(Grafo, j, i);
                }
            }
        }
    }   
    //Imprime Lista de Adjacencias - Representacao grafica
    ImprimeGrafo_ListaAdjacencias(Grafo, NumVertices);
    for(int i = 0; i < NumVertices; i++)
    {
        int Grau = CalculaGrau_ListaAdjacencias(Grafo,i);
        printf("Grau de %d: %i ", Grafo[i].info, Grau);
        printf("\n");
    }
    //Desalocando memória - Lista de Adjacencias
    for(int i = 0; i < NumVertices; i++)
    {   liberaGrafo_ListaAdjacencias(Grafo, i);    }
    free(Grafo);
    //se chegou ate aqui, ocorreu tudo certo
    return SUCESSO;
}
