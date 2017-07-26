#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"

//Alison Gorgonho da Silva
//AED EP 3
//Aquivo main.C
//24/03/17
//
//
//
//



int main()
{

    //Criando variaveis para receber os elmentoss do aqruivo e inicializando a Pilha
    char var_atual;
    Pilha_Contrutor();


    //abrindo o arquivo
    FILE *arquivo = fopen("exp.dat", "r");


    //Loop principal que vai verificar se os parenteses estão balanceados
    while(var_atual != EOF){


        //obtendo o elemento do arquivo
        var_atual = fgetc(arquivo);

        //condicional para adicionar um parenteses na pilha
        if(var_atual == '('){

            //printf("Achei um parenteses !\n");
            Pilha_Push(var_atual);

        }

        //condicional para remover um parenteses na pilha
        if(var_atual == ')'){

            Pilha_Pop();
        }

        //condicional que verifica fim da linha
        if(var_atual == '\n'){

            //condicional que verifica se a expressão esta bem formada
            if(Pilha_Vazia()==1 && Pilha_tamanho() == 0){

                printf("Expressao bem formada.\n");

            }else{

                printf("Expressao mal formada.\n");

            }

            //função que limpa a pilha
            Pilha_Destrutor();

            //printf("Fim de linha\n");

        }

        //condicional que verifica fim do arquivo
        if(var_atual == EOF){

            //condicional que verifica se a expressão esta bem formada
            if(Pilha_Vazia()==1 && Pilha_tamanho() == 0){

                printf("Expressao bem formada.\n");

            }else{

                printf("Expressao mal formada.\n");

            }

            //printf("Fim de arquivo\n");
            //Pilha_tamanho();

            //função que limpa a pilha
            Pilha_Destrutor();

        }

    }








//    Fila_construtor();
//
//    int x=0, y = 0, z;
//
//    for(x=0; x<=10; x++){
//        y++;
//        Fila_Push(x, y);
//    }
//
//    printf("A fila esta com %d elementos.\n",Fila_Tamanho());
//
//    Percorre_Fila();
//
//    Fila_Pop();
//
//    Fila_destrutor();
//
//    Percorre_Fila();
//
//    printf("A fila esta com %d elementos.\n",Fila_Tamanho());

    fclose(arquivo);
    return 0;
}
