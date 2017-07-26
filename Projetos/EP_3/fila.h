
//Alison Gorgonho da Silva
//AED EP 3
//Aquivo fila.h (header)
//14/03/17

//Variavel que armazena a quantidade de elementos da nossa fila
int Fila_contador;


//Fun��o responsavel por apontar o topo da fila para NULL(-1), e zerar a variavel fila_contador
void Fila_construtor();


//Fun��o responsavel por limpar todos os elementos da nossa fila.
int Fila_destrutor();


//Fun��o que verifica se a fila esta vazia
int Fila_Vazia();


//Fun��o que insere um elemento na fila, temos como parametro a coordnada x e a coordenada y
int Fila_Push(int x);


//Fun��o responsavel por remover elementos da nossa fila.
void Fila_Pop();


//Fun��o responsavel por nos informar o tamanho da nossa fila
int Fila_Tamanho();


//Fun��o que retorna umn ponteiro para a celula inicial da fila
struct TipoCelula * Fila_Get();
