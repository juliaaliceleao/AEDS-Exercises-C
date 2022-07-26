/*  Name: Julia Alice Leao
    Date: 2022-06-04
    -- juliaaliceleao@ufmg  --*/
/*Project: QueueParking 
Quando chega um novo carro, este é estacionado em um terreno, um atrás do outro. 
Quando um carro precisa sair, os outros carros são retirado e são colocados no final
da fila pela entrada do estacionamento. Faça um programa que inclua carros no estacionamento
informando o número da placa e retire carros usando o identificador (placa). 
Depois de ter informado a placa, exiba o estado do estacionamento.*/

#include <stdio.h>
#include "fila.h"
#include <stdlib.h>
#include <string.h>

//Constants
#define SUCESS 0
#define numPlate (7+1)
#define EXIT 3
#define ERRO 1

int 
main(int argc, char ** argv)
{
    //Variables
    int num;
    FilaL * queueParking;
    char licensePlate[numPlate];
    
    //creating queue
    queueParking = fila_cria_l();
    printf("Adds one car to queueParking");
    //Readings: fgets reads NumPlate + /0
    printf("\nNumber Plate[7 digits]:\n");
    fgets(licensePlate, numPlate, stdin);
    //add the car to queueParking
    fila_insere_l(queueParking,licensePlate);
    do
    {
        printf("\n1-Insert More Cars\n2-Remove Cars\n3-Exit\n >");
        scanf("%i", &num);
        getchar();
        if(num==1)//Insert
        {
            printf("\nNumber Plate[7 digits]:\n");
            fgets(licensePlate,numPlate, stdin);
            if(fila_busca_l(queueParking, licensePlate) != NULL)
            {   
                printf("Error!Existing car already have the licensePlate"); 
                return ERRO;
            }
            
            else    //add to queue
            {
                fila_insere_l(queueParking,licensePlate); 
                
            }
            
            //printf queueParking
            fila_imprime_l(queueParking);
        }
        else if (num == 2)//Remove
        {
            printf("\nNumber Plate to Remove [7 digits]:\n");
            fgets(licensePlate, numPlate, stdin);
            if(fila_busca_l(queueParking, licensePlate) == NULL)
            {   
                printf("Error!"); 
                exit(1);
            }
            for(Lista * q = queueParking->ini; q != NULL; q = q->prox)
	        {
                char * plate;
                plate = fila_retira_l(queueParking);
                //if queueParkingelement not equal licensePlate
                if(strcmp(licensePlate, plate)==0)
                {
                    printf("Retirou o carro desejado");
                }
                else
                if(strcmp(licensePlate, plate)!=0)
                {
                    fila_insere_l(queueParking,plate);
                }
            }
            //printf queueParking
            fila_imprime_l(queueParking);
        }
    }while(num != EXIT);
    return SUCESS;
}
