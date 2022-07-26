/**
 * @file ListadeAdjacencias.c
 * @Name Julia Alice Leao
 * @Date 2022-07-20
 * @Project Rede de Computadores - Lista de Adjacencias
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
    /* Procurando problemas - 
    em cada um dos 10 servidores deve-se verificar de que
    todos os 8 computadores estao realmente conectados
    nos servidores a quais eles pertencem.
    Se isso for verdadeiro nao havera
	falha de comunicao em nenhum dos servidores */
    
    //Variaveis
    int NumServidores = 10, //Vertices
    NumComputadores = 8;    //Arestas
    
    //Criacao do Grafo
    struct GrafoLista * Grafo =  GrafoLista_cria();
    
    //--Imprimindo Vertices
    ImprimeGrafo_Vertice(NumServidores);
    
    //--Inserindo os Vertices
    Grafo = GrafoLista_InsereVertices(NumServidores);
    //Inserindo as Arestas
    for(int i = 0; i < NumServidores; i++)
    {   
        for(int j = 0; j < NumComputadores; j++)
            InsereGrafo_ListaAdjacencias(Grafo, i, j);
    }
    
    int erro = 0;
    for(int i = 0; i < NumServidores; i++)
    {   
        int Conexoes = CalculaGrau_ListaAdjacencias(Grafo, i);
        if(Conexoes != NumComputadores)
        {
            printf("ERRO** Ha computadores desconectados no Servidor: %i\n",i+1);
            erro++;
        }
    }
    printf("%i erros \n ",erro);
    
    //Desalocando memoria
    //--Desalocando Arestas
    for(int i = 0; i < NumServidores; i++)
        liberaGrafo_ListaAdjacencias(Grafo,i);
    //--Desalocando Vertices
    free(Grafo);
    
    //Caso erro igual a zero(nenhum) retorna SUCESSO(O)
    if(erro == 0)
    {   printf("**Nao ha problemas na Rede Coltecana");
        //se chegou ate aqui, ocorreu tudo certo
        return SUCESSO;
    }
    //Caso tenha erros na rede o programa retorna ERRO(1);
    else 
    return ERRO;
}
