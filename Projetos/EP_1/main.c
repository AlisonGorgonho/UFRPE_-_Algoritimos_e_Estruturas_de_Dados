#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Alison Gorgonho da Silva
Ep1
25/09/2016
Algoritimos e estruturas de dados

/*

Definindo Fórmula de força bruta:

*/

/*

Função que calcula e retorna a distancia entre dois pontos:

*/

double Distancia(int x_1, int y_1, int x_2, int y_2){

    //Definindo variáveis

    int potencia_1, potencia_2;
    double raiz_potencias;
    float resultado;

    //Definindo potencia_1

    potencia_1 = pow((x_1-x_2), 2);
    //printf("%d\n", potencia_1);//Imprimindo valor para verificação

    //Definindo potencia_2

    potencia_2 = ((y_1-y_2)*(y_1-y_2));
    //printf("%d\n", potencia_2);//Imprimindo valor para verificação

    //Definindo raiz_potencias

    raiz_potencias = (potencia_1 + potencia_2);

    //Definido variável final

    resultado = sqrt(raiz_potencias);

    //Retornando resultado do cálculo da distancia entre duas coordenadas

    //printf("A distancia entre as duas coordenadas eh: %f\n", resultado);//Imprimindo valor para verificação

    return resultado;

}

/*

Função que verifica a menor distancia entre as coordenadas por meio da força bruta:

*/

void Elementar(int *vet_x[], int *vet_y[], int len){

    int minimo = 9999999999999999;
    int i, j, indice_1, indice_2;
    float dist;

    for(i = 0; i < len - 1; i++){
            //printf("%d\n", i);

        for(j = 1; j < len ; j++){
                //printf("%d\n", j);


                if(j != i){

                    //printf("Lista 1 x = %d, Lista 1 y = %d \ Lista 2 x = %d, Lista 2 y = %d.\n", vet_x[i], vet_y[i], vet_x[j], vet_y[j]);
                    dist = Distancia(vet_x[i], vet_y[i], vet_x[j], vet_y[j]);
                    //printf("Distancia = %f\n", dist);
                }

                if(dist < minimo){

                    indice_1 = i;
                    indice_2 = j;
                    minimo = dist;
            }

        }
    }

    //printf("Minimo = %d.\n", minimo);

    printf("%d, %d\n", i, j);
    printf("%d\n", minimo);

}




int main()
{
    int len_lista, i, j, minimo;
    int vetor_x[1000], vetor_y[1000];
    FILE *arquivo = fopen("trembala.txt", "r");

    while(len_lista != 0){


        fscanf(arquivo, "%d", &len_lista);
        //printf("\n%d\n", len_lista);
        for(i = 0; i < len_lista; i++){
            fscanf(arquivo, "%d", &vetor_x[i]);
            //printf("\n%i", vetor_x[i]);
        }
        for(j = 0; j < len_lista; j++){
            fscanf(arquivo, "%d", &vetor_y[j]);
            //printf("\n%j", vetor_y[j]);
        }
        if(len_lista == 0){

            break;
        }

        Elementar(vetor_x, vetor_y, len_lista);
        break;

    }

    return 0;
}
