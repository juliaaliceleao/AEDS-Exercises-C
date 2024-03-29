/*  Nome: Julia Alice Leao
    Data: 2022-05-05
    -- juliaaliceleao@ufmg  --  */

/* Problema de Josephus:um certo Flavius Josephus,
durante uma guerra, se encontrava entre um bando de 41 rebeldes
encurralados pelos seus inimigos em uma caverna. Os rebeldes formam
um círculo e começam a partir de certo ponto a executar a terceira
pessoa numa direção. Sabe-se que Josephus sobreviveu. Em que posição
ele estava para ser o último? De forma geral, dada uma função
(número de pessoas, passos), em que posição Josephus deve ficar para
se salvar? Implemente o problema de Josephus utilizando Lista Encadeada. */

//bibliotecas
#include <stdio.h>
#include "listas.h"

//constantes
#define SUCESSO 0

int
main (int argc, char ** argv)   //Inicio do main
{
  //Declaracao de Variaveis
  Lista * listasoldados;
  int numSoldados = 41, posicaosoldado = 0;
  
  listasoldados = lst_cria();//criando lista de soldados
  
  //inserindo o numero de cada soldado em cada info
  //do 1 a 41 soldado
  for(posicaosoldado = 1; posicaosoldado <= numSoldados; posicaosoldado++)
  {
    listasoldados = lst_insere (listasoldados, posicaosoldado);
  }
  
  // tornando a lista circular
  listasoldados = lcirc_transforma (listasoldados);

  while(numSoldados != 1)//enquanto restar mais que um soldado
  {
    for(posicaosoldado = 1; posicaosoldado <= 3; posicaosoldado++)//de 3 em 3
    {
      if(posicaosoldado == 3) //elimina o terceiro da lista
      {
        listasoldados->prox = listasoldados->prox->prox;
        numSoldados--; //menos um soldado
      }
      if(listasoldados->info != listasoldados->prox->info)
      listasoldados=listasoldados->prox;
    }
  }
  printf("Josephus estava na posição ");
  lcirc_imprime(listasoldados);
  
  return SUCESSO;
}
