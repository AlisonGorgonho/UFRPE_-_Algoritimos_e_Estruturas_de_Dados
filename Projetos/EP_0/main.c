#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/*

Nome: Alison Gorgonho da Silva
Ep: 0
Disciplina: Algoritimos e esetruturas de dados
Data: 28/08/2016

*/


//Função que verifica se o vetor esta ordenado
//Retorna -1 para ordenado e 0 para não ordenado
int ver_Ordenacao(int *vet, int len){

    int ordem = -1, i = 0;

    for(i ;i < len; i++){

        //printf("\n%d : %d", vet[i], vet[i+1]);

        if(vet[i] > vet[i+1]){

            ordem = 0;

        }

    }

    //printf("\n%d",ordem);

    return ordem;
}

//Função que verifica onde começa os efeitos da avalanche
int ver_InicioAvalanche(int *vet, int len){

    int pos = -1, num_atual, i = 0, j;

    while(pos == -1){

        for(i ;i < len; i++){

            num_atual = vet[i];
            //printf("\n%d", num_atual);

                for(j = i+1; j < len; j++){
                    //printf("\n%d : %d", num_atual, vet[j]);
                    if(num_atual > vet[j]){

                        pos = i+1;
                        //printf("\n%d", pos);
                        break;
                    }
                }

                if(pos != -1){

                    break;

                }

            }

    }

    //printf("\n%d", pos);

    return pos;
}

// Função que ordena e imprime os valores ordenados a tela
void alg_Insercao(int num_P, int *vet, int pos) {
   int var_aux, i, j;
   for (i = pos; i < num_P; ++i) {
      j = i;
      //printf("\n%d", vet[i]);

      while(vet[j] < vet[j-1] && j > pos-1){

        var_aux = vet[j];
        vet[j]=vet[j-1];
        vet[j-1] = var_aux;
        //printf("%d", vet[j]);

        j--;
      }

   }

   for(i = pos-1; i < num_P; i++){

        printf("%d ", vet[i]);
   }

}


void main()

{
    int num_Pistas, i, var_aux;
    int vetor[1000];
    FILE *arquivo = fopen("teste.txt", "r");

    while(num_Pistas != 0){


        fscanf(arquivo, "%d", &num_Pistas);
        //printf("\n%d\n", num_Pistas);
        for(i = 0; i < num_Pistas; i++)
            fscanf(arquivo, "%d", &vetor[i]);
            //printf("\n%i", vetor[i]);

        if(num_Pistas == 0){

            break;
        }
        if(ver_Ordenacao(vetor, num_Pistas) != -1){

              printf("%d ", ver_InicioAvalanche(vetor, num_Pistas));
              alg_Insercao(num_Pistas, vetor, ver_InicioAvalanche(vetor, num_Pistas));
              printf("\n");


        }
        else if(ver_Ordenacao(vetor, num_Pistas) == -1){

            printf("%d", -1);
            printf("\n");
        }

        for(i = 0; i < num_Pistas; i++){

            //printf("%d", vetor[i]);
        }

    }
}
