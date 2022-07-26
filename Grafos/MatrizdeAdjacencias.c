/**
 * @file MatrizdeAdjacencias.c
 * @Name Julia Alice Leao
 * @Date 2022-07-20
 * @Project Matriz de Adjacencias
 * -- juliaaliceleao@ufmg  --
*/

//Inclusoes
#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

//Constantes
#define SUCESSO 0
#define ERRO 1

int 
main(int argc, char ** argv)
{
    //Variaveis
    int NumVertices; //Armazenando o numero de vertices
    
    //Criacao do Grafos
    //--Leitura de NumVertices
    printf("Num. Vertices: ");
    scanf("%i", &NumVertices);
    if(!NumVertices) //se NumVertices for == 0, encerre aqui
        return ERRO;
    
    struct Grafo * Grafo =  Grafo_cria();
    
    //--Imprimindo um grafo sem arestas com a funcao ASCIIGrafo
    ImprimeGrafo_Vertice(NumVertices);
    
    //--Inserindo os Vertices
    Grafo = Grafo_InsereVertices(NumVertices);
    //Inserindo as Arestas
    InsereGrafo_MatrizAdjacencias(Grafo, NumVertices);
    
    //Imprime Matriz Adjacencias
    ImprimeGrafo_MatrizAdjacencias(Grafo, NumVertices);
    
    for(int i = 0; i < NumVertices; i++)
    {
        int Grau = CalculaGrau_MatrizAdjacencias(Grafo, i, NumVertices);
        printf("Grau de %d: %i ", Grafo[i].info, Grau);
        printf("\n");
    }
    
    //Desalocando a memoria
    // - Matriz Adjacencias
    liberaGrafo_MatrizAdjacencias(Grafo, NumVertices);
    
    //se chegou ate aqui, ocorreu tudo certo
    return SUCESSO;
}
