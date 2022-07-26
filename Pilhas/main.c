/*  Nome: Julia Alice Leao
    Data: 2022-08-05
    -- juliaaliceleao@ufmg  --*/
    
/*Descricao: um programa para determinar se a sequência
de parênteses está bem formada (ou seja, se os
pareteses foram fechados na ordem inversa
aquela em que foram abertos).*/

//bibliotecas
#include <stdio.h>
#include "pilhas.h"
#include <stdlib.h>

//constantes
#define SUCESSO 0
#define VERDADEIRO (1==1)
#define FALSO (!VERDADEIRO)
int 
main(int argc, char ** argv)
{
    //Variaveis
    char usuario;   //parenteses que sera lido do usuario
    int abertolido = 0, fechado = 0, i;
    int NumParenteses;
    Pilha_lst * pilhadeparenteses;
    
    //Leitura
    printf("Digite o tamanho da sua sequencia de parenteses:\n >");
    scanf("%i", &NumParenteses);
    
    pilhadeparenteses = pilha_lst_cria();
    
    printf("\nDigite a sua sequencia de parenteses.\n");
    for(i = 0; i < NumParenteses; i++)
    {
        printf(">");
        getchar();
        scanf("%c", &usuario);
        
        if(usuario =='(')
        {
            pilha_lst_push(pilhadeparenteses, usuario);
            abertolido++;//contando abertos lidos
        }
        
        else
        if(usuario == ')' && i > 0)
        {
            char comparacao = pilha_lst_pop(pilhadeparenteses);
            if(comparacao == '(')
            {
                fechado++;  //um par de parenteses foi fechado
            }
        }
    }
    if(fechado==abertolido && i>0)
    {
        printf("A expressao eh bem formada.");
        
    }
    else
    {
        printf("A expressão eh mal formada.");
    }
    return SUCESSO; //tudo sobre o controle, o programa retorna sucesso.
}
