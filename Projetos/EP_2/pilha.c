
//Alison Gorgonho da Silva
//AED EP 2
//Aquivo pilha.C
//14/03/17
//
//
//
//





//Criação da estrutura TipoCelula, responsavel por armazenar nossos valores de coordenadas e o ponteiro para o proximo elemento da pilha
struct TipoCelula{
    int x, y;
    struct TipoCelula *prox;
};


//Variavel que armazena a quantidade de elementos temos em nossa pilha
int Pilha_contador = 0;


//Criando umm ponteiro do tipo TipoCelular que vai se chamar topo
struct TipoCelula *Topo;


//Função que o topo da nossa pilha vai apontar para NULL(-1)
//OBS: Tive problemas na utilização do NULL, por isso optei por usar -1
void Pilha_Contrutor(){
    Topo=-1;
    Pilha_contador=0;
}


//Função responsavel por desempilhar todos os elementos da nossa pilha, nos utilizamos de um ponteiro do tipo TipoCelula para não perdermos o ponteiro do nosso topo enquanto desempilhamos os elementos
int Pilha_Destrutor(){

    struct TipoCelula *Temp;
    //Se a pilha estiver vazia retornamos 0 e paramos a operação de desempilhar.
    if(Pilha_Vazia()){
        return 0;

    //Caso contrario Apontamos Temp para o elemento que esta no topo da pilha, por questão de segurança apontamos o atributo prox de temp para desligalo totalmente da pilha, apontamos topo para o atributo prox de topo, e liberamos o espaço alocado para o ponteiro temporario
    }else{
        while(Topo!=-1){
            Temp=Topo;
            Temp->prox=-1;
            Topo=Topo->prox;
            free(Temp);
        }
        //Como desempilhamos todos os elementos da nossa pilha, o contador vai para 0
        Pilha_contador=0;
        return 1;
    }


}


//Função que verifica se a nossa pilha está vazia, observamos o Ponteiro topo, se o mesmo apontar para null, quer dizer que a pilha não possui nenhum elemento. Retornamos 1 para vazia e 0 para não vazia
int Pilha_Vazia(){
    if(Topo==-1){
        return 1;
    }else{
        return 0;
    }
}


//Função PUSH, responsavel por inserir elementos na nossa pilha, primeiriamente recebemos como parametros x e y que são os valores da nossa coordenada, criamos um novo ponterio do tipo TipoCelula, e alocamos o espaço necessario para ele.
//Caso o sistema operacional nao liberar a memoria que tentamos alocar para a nova celular, retornamos 0, caso contrario setamos os parametros nos atributos da nova celular e apontamos o atributo proximo para topo
//Nosso topo agora é igual a nova celula, adicionamos 1 no PIlha_contador por termos adicionado um elemento na nossa pilha e retornamos 1
int Pilha_Push(int x, int y){
    struct TipoCelula *Nova_Celula = (struct TipoCelula*)malloc(sizeof(struct TipoCelula));

    if(Nova_Celula==-1){
        return 0;
    }else{
        Nova_Celula->x=x;
        Nova_Celula->y=y;
        Nova_Celula->prox=Topo;
        Topo=Nova_Celula;
        Pilha_contador++;
        return 1;
    }
}


//Função responsavel por desempilhar um elemento da nossa pilha, primeiramente criamos um ponteiro temp do tipo TipoCelula c para podermos desempilhar sem perder os ponteiros nas operações
//Verificamos se a pilha esta vazia, se estiver retornamos 0, caso contrario apontamos temp para topo, e topo para topo->proximo, por medida de segurançã apontamos tempo->prox para NULL(-1)
//liberamos o espaço que o elemento ocupava, subtraimos 1 de pilha_contador e retornamos 1
void Pilha_Pop(){
    struct TipoCelula *Temp;
    //int array[2];
    if(Pilha_Vazia()==1){

        //printf("Lista vazia !!\n");

    }else{


        //array[0]=Topo->x;
        //array[1]=Topo->y;


        Temp = Topo;
        Topo = Topo->prox;
        Temp->prox=-1;//Medida de segurançã para desligar a celula da pilha.
        free(Temp);
        Pilha_contador--;

        //printf("%d,%d\n", array[0], array[1]);
    }
}


//Função que retorna o valor guardado em PIlha_contador
int Pilha_tamanho(){
    //printf("A pilha tem: %d  elementos\n", Pilha_contador);
    return Pilha_contador;
}


//Função que retorna os atributos de coordenadas dos elementos no topo da pilha.
int * Pilha_Get(){

    if(Pilha_Vazia()==1){

        return -1;

    }else{

        int array[2];
        array[0]=Topo->x;
        array[1]=Topo->y;

        return array;

    }
}

