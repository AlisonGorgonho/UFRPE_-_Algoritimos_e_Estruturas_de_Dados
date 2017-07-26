
//Alison Gorgonho da Silva
//AED EP 3
//Aquivo fila.c
//24/03/17
//
//
//
//




//Criação da estrutura TipoCelula, responsavel por armazenar nosso valor e o ponteiro para o proximo elemento da fila.
struct TipoCelula{

    int x;

    struct TipoCelula *prox;
};


//Variavel que armazena a quantidade de elementos temos em nossa fila
int Fila_contador = 0;


//Criando umm ponteiro do tipo TipoCelula que vai se chamar topo
struct TipoCelula *Inicio;


//Criando umm ponteiro do tipo TipoCelula que vai se chamar FIm
struct TipoCelula *Fim;


//Função que verifica se a nossa fila está vazia, observamos o Ponteiro topo, se o mesmo apontar para null, quer dizer que a fila não possui nenhum elemento. Retornamos 1 para vazia e 0 para não vazia
int Fila_Vazia(){

    if(Inicio==-1){

        return 1;
    }else{

        return 0;
    }

};


//Função que o topo da nossa fila vai apontar para NULL(-1)
//OBS: Tive problemas na utilização do NULL, por isso optei por usar -1
void Fila_construtor(){

    Inicio = -1;
    Fim = -1;
    Fila_contador = 0;

};


//Função responsavel por desemfilar todos os elementos da nossa fila, nos utilizamos de um ponteiro do tipo TipoCelula para não perdermos o ponteiro do nosso topo enquanto desemfilamos os elementos
int Fila_destrutor(){

    struct TipoCelula *Temp;

    if(Fila_Vazia()==11){
        printf("A fila esta vazia !");
        return 0;
    }else{
        while(Inicio!=-1){

            Temp=Inicio;
            Temp->prox=-1;
            Inicio=Inicio->prox;
            free(Temp);
        }
        Fim=-1;
        Fila_contador=0;
        return 1;
    }
}


//Função PUSH, responsavel por inserir elementos na nossa fila, primeiriamente recebemos como parametros x, criamos um novo ponterio do tipo TipoCelula, e alocamos o espaço necessario para ele.
//Caso o sistema operacional nao liberar a memoria que tentamos alocar para a nova celular, retornamos 0, caso contrario setamos os parametros nos atributos da nova celular e apontamos o atributo proximo para topo
//Nosso topo agora é igual a nova celula, adicionamos 1 no fila_contador por termos adicionado um elemento na nossa fila e retornamos 1
int Fila_Push(int x, int y){


    struct TipoCelula *Nova_Celula = (struct TipoCelula*)malloc(sizeof(struct TipoCelula));

    if(Nova_Celula==-1){

        printf("Memoria não alocada ! !\n");
        return 0;
    }else{

        Nova_Celula->x=x;
        if(Fila_Vazia()==1){

            Inicio = Nova_Celula;
            Nova_Celula->prox = -1;
            Fim = Nova_Celula;
            Fila_contador++;
        }else{

            struct TipoCelula *Temp;
            Temp = Inicio;
            while(Temp->prox != -1){

                Temp = Temp->prox;
                //printf("%d\n", Temp);

            }

            Temp->prox=Nova_Celula;
            Fim = Nova_Celula;
            Nova_Celula->prox = -1;
            Fila_contador++;


        }

        printf("Inserimos o elemento %d\n", Nova_Celula->x);
        return 1;
    }


}


//Função responsavel por desemfilar um elemento da nossa fila, primeiramente criamos um ponteiro temp do tipo TipoCelula c para podermos desemfilar sem perder os ponteiros nas operações
//Verificamos se a fila esta vazia, se estiver retornamos 0, caso contrario apontamos temp para topo, e topo para topo->proximo, por medida de segurançã apontamos tempo->prox para NULL(-1)
//liberamos o espaço que o elemento ocupava, subtraimos 1 de fila_contador e retornamos 1
void Fila_Pop(){

    struct TipoCelula *Temp;

    if(Fila_Vazia()==1){
        Fim=-1;
        printf("A fila esta vazia !");
    }else{

        //printf("O atributo do elemento removido foi: %d", Inicio->x);
        Temp = Inicio;
        Inicio = Inicio->prox;
        Temp = -1;
        free(Temp);
        Fila_contador--;


    }
}


//Função que retorna o valor guardado em fila_contador
int Fila_Tamanho(){

    return Fila_contador;

}



void Percorre_Fila(){

    struct TipoCelula *Temp;
    Temp = Inicio;

    int cont=0;

    if(Fila_Vazia()==1){

        printf("A fila esta vazia !\n");
    }else{
        while(Temp != -1){

            printf("Elemento %d possui o atributo%d\n", cont, Temp->x);

            //printf("%d", Temp->prox);
            Temp=Temp->prox;
            cont++;
        }

    }

}


//Função que retorna os atributos de coordenadas dos elementos no topo da fila.
struct TipoCelula * Fila_Get(){


    if(Fila_Vazia()==1){

        printf("Fila vazia !");
    }else{
        return Inicio;

    }





}














