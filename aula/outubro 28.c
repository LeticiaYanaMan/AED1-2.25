// ESTRUTURA DE UM NÓ

typedef struct {
int valor;
struct No* proximo;
} No;

#include "lista.h"
int main() {
  No* lista = NULL; //sempre declaa como ponteiro E coloca o & nas funções
  //codigo aqui
  //inserindo valores na lista, no inicio
  inserir_inicio(&lista, 1); //passa o endereço do ponteiro (uma variavel)

// Lista encadeada -> encadeamento de nós
// primeiro: cabeça -> último colocado

//INSERIR COMEÇO
void inserir_inicio(No** cabeca, int valor) { //dois ponteiros: endereço do endereço do nó
  No* novo_no = malloc(sizeof(No));
  novo_no->valor = valor;
  novo_no->proximo = *cabeca;
  *cabeca = novo_no;
}

//outra forma:
No* inserir_inicio(No* cabeca, int valor) {
  No* novo_no = malloc(sizeof(No));
  novo_no->valor = valor;
  novo_no->proximo = *cabeca;
  *cabeca = novo_no;
  return novo_no;
} // precisa, no main, colocar lista = inserir_inicio(lista, 10);

// INSERIR FIM
void inserir_fim(NO** cabeca, int valor) {
  // as primeiras tres linhas está criando um novo nó
  No* novo_no = malloc(sizeof(No));
  novo_no->valor = valor;
  novo_no->proximo = NULL;
  //prox 2 linhas - percorre --- se a cabeça esta vazia(NULL), coloca o novo no ali
  if (*cabeca == NULL) {
    *cabeca = novo_no;
  } else {  // o else é para terminar
    No* temp = *cabeca; //inicia temp, que vai percorrer o codigo, na cabeca
     // o whle ali no else é percorrendo (o pximo é nulo? Não? avança --- se sim!, sai do looping e adiciona o novo_no
    while (temp->proximo != NULL) {
      temp = temp->proximo;
    temp->proximo = novo_no;
    }
  }
}

// BUSCA

No* buscar(No * cabeca, int valor) {
    No* temp = cabeca;
    while(temp != NULL) {
      if(temp->valor == valor) {
        return temp; //retorna o endereço de memoria do nó que tem esse valor
      }
      temp = temp->proximo;
    }
    return NULL;
}

// REMOÇÃO DO NÓ
void remover_primeiro(No ** cabeca) { //remove o primeiro elemento
  if (*cabeca == NULL) return;
  No* temp = *cabeca;
  *cabeca = temp->proximo;
  free(temp);
}

void remover_ultimo(No ** cabeca) {
  if(*cabeca == NULL) return;
  No* temp = *cabeca;
  No* anterior = NULL;
  while (temp->proximo != NULL) {
    anterior = temp;
    temp = temp->proximo;
  }
  if (anterior == NULL) 
    *cabeca == NULL;
  else 
    anterior->proximo = NULL;
  free(temp);
}

//remover um específico
// 1. buscar e ecotrar o que você quer remover - se eu quero remover esse, eu não posso dar free porque tudo que está depois se perde
    // precisa conectar o anterior ao proximo e depois consegue dar free (anterior->prox = temp->prox) 
    // ai você pode dar free

//precisa ver se não está vazio (cabeça != NULL) 
void remover(No** cabeca, it valor) {
  No* temp = *cabeca;
  No* anterior = NULL;
  while (temp != NULL && temp->valor != valor) { // temp!= NULL é não encontrado - chegou no final
    anterior = temp;
    temp = temp->proximo;
  }
  if (temp == NULL) return; //valor não encontrado - não faz nada
  if (anterior == NULL) //caso o valor esteja na cabeca
    *cabeca = temp->proximo;
  else
    anterior->proximo = temp->proximo;
  free(temp);
}

// EXERCICIO - ESTUDAR UM FIBONACCI ASSIM

//PILHA:
    //push: inserir_inicio
    //pop: remover_primeiro
    //peek: retornar valor da cabeça (o ultimo numero que entrou é a cabeca)
  // LISTA ENCADEADA tem o mesmo conceio de PILHA
    //NÚMERO DE ELEMENTOS DA PILHA - percorrer a pilha
      // cria uma nova estrutura -> 
    //Pilha vazia se cabeca == NULL

//PILHA:
    //insert: inserir_fim
    //remove: remover_primeiro
    //search: buscar
  // cabeca = primeiro elemento da fila
  // numero de elementos = percorrer a fila
  // fila vazia = cabeca==NULL
// custo muito alto para enfileiras (insert)

//apontador para o fim
// estrutura para um nó da fila + estrutura para representar a fila
// init_fila
// fução  para enfileirar (insert) elemento

void enfileirar(Fila* fila, int valor) {
  No* novo_no = (No*) malloc(sizeof(No));
  novo_no->valor = valor;
  novo_no->proximo = NULL;

  if (fila->fim == NULL) { //vazia 
    fila->inicio = novo_no;
  } else {
      fila->fim->proximo = novo_no;
  }
  fila->fim = novo_no; //fora do if - sempre faz 
}

// FILA CIRCULAR
    // pode ser usando apenas No ou criando fila para incluir o No inicio
    // lista tem um no cabeca que não é removida, mesmo se ficar vazia 
    // prmeiro elemento -> proximo no da cabeca
    /;ultimo elemento fica no no anterior a cabeca 

No* colocanaFila (int y, No* cabeca) {
  No* novo;
  novo = malloc(sizeof(No));
  novo->proximo = cabeca->proximo;
  cabeca->proximo = novo;
  cabeca->valor = y;
  return novo; // a nova cabeca é o que voce inseriu (o ultimo elemento que voce inseriu), que aponta para o primeiro elemento que entrou
} // a cabeca vai rotacionando e o primeiro você nu8nca perde, porque é sempre o prixmo do ultimo que você inseriu 

// TALVEZ TENHA QUE COLOCAR FILA CIRCULAR EXATAMENTE COM LISTA ENCADEADA --- alguns são muito grande como fila porque tem que percorrer tudo, essa é muito mais rapida




// OPERACOES COM LISTAS E VETORES

// COPIAR LISTA - COPIA POR VALOR
  // está recursiva
No* copiar_lista(No* lista) {
  if(lista == NULL)
    return NULL;
  novo = malloc(sizeof(No));
  novo->valor
    }



// INVERTER LISTA 
      // pode inverter na propria lista ou criar uma copia invertida - depende do enunciado

// CONCATENAR LISTA 
      // juntar duas listas, A e B (pode colocar tudo em lista A ou criar uma nova lista C)


// LISTA CIRCULAR VERSÃO 2 - SEGUINDO A LOGICA DE UMA PILHA
// INSERIR
// REMOVER

// DUPLAMENTE ENCADEADAS 
     // INSERIR
     // REMOVER
     // CIRCULAR









  







