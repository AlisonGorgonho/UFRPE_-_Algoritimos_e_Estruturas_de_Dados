
//Alison Gorgonho da Silva
//AED EP 2
//Aquivo pilha.h (header)
//14/03/17

//Variavel que armazena a quantidade de elementos da nossa pilha
int Pilha_contador;

//Função responsavel por apontar o topo da pilha para NULL(-1), e zerar a variavel PIlha_contador
void Pilha_Contrutor();


//Função responsavel por limpar todos os elementos da nossa pilha.
int Pilha_Destrutor();


//Função que verifica se a pilha esta vazia
int Pilha_Vazia();


//Função que insere um elemento na pilha, temos como parametro a coordnada x e a coordenada y
int Pilha_Push(int x, int y);


//Função responsavel por remover elementos da nossa pilha.
int * Pilha_Pop();


//Função responsavel por nos informar o tamanho da nossa pilha
int Pilha_tamanho();


//Função que retorna os as coordenadas do elemento que esta no topo da nossa pilha
int * Pilha_Get();
