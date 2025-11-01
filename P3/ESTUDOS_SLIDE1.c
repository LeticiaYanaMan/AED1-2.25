//P3 - 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//NÓS -------------------------------------------------------
//ESTRUTURA
typedef struct {
  int valor; 
  struct No* proximo;
} NO; //quando for utilizar, definir NO *lista = NULL

//INSERRIR - INICIO
//criar um novo no e ajustar os ponteiros para inserir no inicio
//atualizar o ponteiro inicial da lista (cabeca)
void inserir_inicio(NO** cabeca, int valor) { //inserir_inicio(&lista, 1) - vai inserir o valor 1
  NO* novo_no = malloc(sizeof(NO));
  novo_no->valor = valor;
  novo_no->proximo = *cabeca; //o que é atualmente definido como cabeça vira o que esse novo_no aponta
  *cabeca = novo_no;
}

// INSERIR - FINAL
// percorrer lista até o final e inserir o novo nó
// ajustar pontiero do último nó para apontar para o novo.
void inserir_fim(NO** cabeca, int valor) { //inserir_fim(&lista, 11)
  //definindo um novo nó
  NO* novo_no = malloc(sizeof(NO));
  novo_no->valor = valor;
  novo_no->proximo = NULL; //não vem nada depois desse nó - não aponta para nada, por enquanto
  //caso a fila esteja vazia
  if (*cabeca = NULL) 
    *cabeca = noo_no;
  else {
    NO* temp = *cabeca;
    // percorre toda a lista até chegar no nó que não aponta para nada (temp->proximo = NULL);
    while(temp->proximo != NULL) 
      temp = temp->proximo;
    // faz esse último elemento apontar para o que acabamos de criar
    temp->proximo = novo_no;
  }
}

//BUSCAR 
//percorrer a lista para encontrar o valor especificado
//retornar o nó encontrado ou NULL, se não foi encontrado
NO* bsucar(NO* cabeca, int valor) {
  //começa a busca pelo começo - a cabeca
  NO* temp = cabeca;
  //vai ser NULL quando temp->proximo foi NULL
  while (temp != NULL) {
    if (temp->valor == valor) 
      return temp;
    // vai para o proximo valor da lista - se for NULL (aquele foi o ultimo elemento), vai sair do while
    temp = temp->proximo;
  }
  return NULL;
}

// REMOÇÃO DO PRIMEIRO NÓ
//ajustar ponteiros para excluir o nó
//liberar memoria alocada para o no removido

void remover_primeiro(NO** cabeca) { //remover_primeiro(&lista)
  if (*cabeca == NULL) return;
  NO* temp = *cabeca;
  *cabeca = temp->proximo;
  free(temp);

//REMOÇÃO DO ÚLTIMO NÓ
// ajustar ponteiros para excluir o último nó
// liberar memória alocada para o nó removido

void remover_ultimo(NO** cabeca) { // remover_ultimo(&lista)
  // se estiver vazia, não há o que retornar
  if ( *cabeca == NULL) return;
  // cria um que indica qual é o primeiro elemento e qual é o que vem antes desse
  NO* temp = *cabeca;
  NO* anterior = NULL;
  //percorre a lista com o temp e o outro sempre acompanhando, apontando para o anterior
  while (temp->proximo != NULL) {
    anterior = temp;
    temp = temp->proximo;
  }
  // se o anterior for NULL, significa que só tem um elemento: a cabeca 
  if (anterior == NULL) *cabeca = NULL;
  // se chegar no final da fila e o anterior não for NULL, significa que esse valor que o anterior aponta vai apontar para o NULL
    // e o temp (que o temp->proximo == NULL, portanto é o ultimo e saiu do while) vai ser esvaziado
  else 
    anterior->proximo = NULL;
  // esvazia o temp
  free(temp);
}
    
// REMOÇÃO DE UM NÓ ESPECÍFICO
// ajustar ponteiros para excluir o nó com um valor especificado;
// liberar memoria alocada para o no removido
void remover(NO** cabeca, int valor) {
  // mesma coisa do remoção - cria um que percorre e um que vem atrás
  NO* temp = *cabeca;
  NO* anterior = NULL;
  // faz a busca até acabar a lista (== NULL) ou até achar o valor (= valor)
  while (temp != NULL && temp->valor != valor) {
    anterior = temp;
    temp = temp->proximo;
  }
  // se acabar a lista, retorna nada porque não há esse numero na lista
  if (temp == NULL) return;
  // se chegou em algo e anterior == NULL, significa que é a cabeca que vai esvaziar
  // passa o indicador de cabeca para o proximo no
  if (anterior == NULL) *cabeca = temp->proximo;
  // se não, faz o link entre o proximo do anterior e o proximo do temp 
  // temp fica meio sobrando - consegue dar free
  else anterior->proximo = temp->proximo;
  // vai dar free de qualquer modo, encontrando o valor ou n, por isso não está com nenhuma função
  free(temp);
}


// PILHA -------------------------------------------------------
// cabeca - topo da pilha
// numero de elementos: percorrer a pilha (lista)
// pilha vazia -> cabeca NULL
  // PUSH - inserir_inicio
  // POP - remover_primeiro
  // PEEK - retornar valor da cabeca

// FILA -------------------------------------------------------
// cabeca - primeiro elemento da fila
// numero de elementos: percorrer a fila (lista)
// fila vazia -> cabeca NULL
    // INSERT - inserir_fim (custo alto)
    // REMOVE - remover_primeiro 
    // SEARCH - buscar 


//outro jeito de INSERT (fila) com um custo menor:
// definir a estrutura de Nós
typedef struct {
  int valor;
  struct NO* proximo;
} NO;
// definir a estrutura para representar a fila
typedef struct {
  NO* inicio;
  NO* fim;
} Fila;
//ENFILEIRAR
Fila* criar_fila() {
  Fila* nova_fila = (Fila*) malloc(sizeof(Fila));
  nova_fila->inicio = NULL;
  nova_fila->fim = NULL;
  return nova_fila;
}

// FILA CIRCULAR ------------------------------------------------------------
/*
int main() {
  NO* fila = NULL;
  fila = malloc(sizeof(NO));
  fila->proximo = fila;
  fila = colocanafila(12,fila);
}
*/

NO* colocanafila(int y, NO* cabeca) {
  NO* novo;
  novo = malloc(sizeof(NO));
  novo->proximo = cabeca->proximo;
  cabeca->proximo = novo;
  cabeca->valor = y;
  return novo;
}

// circular 2
NO* inserir_circular(NO* lista, int x) {
  // cria um novo no
  NO* novo;
  novo = malloc(sizeof(NO));
  novo->dado = x;

  if (lista == NULL) {
    novo->proximo = novo;
    lista = novo;
  } else {
    novo->proximo = lista->proximo;
    lista->proximo = novo;
  }
  return lista;
}


// OPERAÇÕES EM LISTAS E VARIAÇÕES ------------------------------------------------------------
// COPIAR LISTA (RECURSIVA)
NO* copiar_lista(NO* lista) {
  NO* novo = NULL;
  if (lista == NULL) return NULL;
  novo = malloc(sizeof(NO));
  novo->valor = lista->valor;
  novo->proximo = copiar_lista(lista->proximo);
  return novo;
}

// INVERTER LISTA (ITERATIVA)
NO* inverter_lista(NO* lista) {
  NO* atual, ant, invertida = NULL;
  atual = lista;
  while (atual != NULL) {
    ant = atual;
    atual = atual->proximo;
    ant->proximo = invertida;
    invertida = ant;
  }
  return invertida;
}

// CONCATENAR (JUNTAR LISTAS) (RECURSIVA)
NO* concatenar_lista(NO* primeira, NO* segunda) {
  if (primeira == NULL) return segunda;
  primeira->proximo = concatenar_lista(primeira->proximo, segunda);
  return primeira;
}

// LISTAS DUPLAMENTE ENCADEADAS ------------------------------------------------------------

// define o no diferentemente
typedef struct NO {
  int valor;
  struct NO* proximo;
  struct NO* anterior;
} NO;

NO* insereInicio(NO* inicio, int valor) {
  NO* novo = (NO*)malloc(sizeof(NO));
  novo->valor = valor;
  novo->proximo = inicio;
  novo->anterior = NULL;

   if (inicio != NULL) inicio->anterior = novo;
   return novo;
}

NO* insereFim(NO* inicio, int valor) {
  NO* novo = (NO*)malloc(sizeof(NO));
  novo->valor = valor;
  novo->proximo = NULL;
  if (inicio == NULL) {
    novo->anterior = NULL;
    return novo;
  }
  NO* fim = inicio;
  while (fim->proximo != NULL)
    fim = fim->proximo;
  fim->proximo = novo;
  novo->anterior = fim;
  return inicio;

NO* removeValor(NO* inicio, int valor) {
  NO* atual = inicio;
  while(atual != NULL && atual->valor != valor) 
    atual = atual->proximo;
  if (atual == NULL) {
    printf("Valor não encontrado na fila\n");
    return inicio;
  }
  if (atual->anterior != NULL) 
    atual->anterior->proximo = atual->proximo;
  else
    inicio = atual->proximo;
  if (atual->proximo != NULL) 
    atual->proximo->anterior = atual->anterior;
  free(atual);
  return inicio;

  
// LISTAS DUPLAMENTE ENCADEADAS CIRCULARES ------------------------------------------------------------

//estrutura para um nó
typedef struct {
  int valor;
  struct NO* proximo;
  struct NO* anterior;
} NO;

//estrutura para a lista
typedef struct {
  NO* inicio;
  NO* fim;
} Lista;

void inserir_inicio(Lista* lista, int valor) {
  NO* novo_no = (NO*)malloc(sizeof(NO));
  novo_no->valor = valor;
  novo_no->anterior = NULL;

  if (lista->inicio == NULL) {
    novo_no->proximo = NULL;
    lista->fim = novo_no;
  } else {
    novo_no->proximo = lsita->inicio;
    lista->inicio->anterior = novo_no;
    lista->inicio = novo_no;
  }
}

void inserir_fim(Lista* lista, int valor) {
  NO* novo_no = (NO*)malloc(sizeof(NO));
  novo_no->valor = valor;

  if (lista->inicio == NUL) {
    novo_no->proximo = novo_no;
    novo_no->anterior = novo_no;
    lista->inicio;
  } else {
    NO* fim = lista->inicio->anterior;
    novo_no->proximo = lista->inicio;
    novo_no->anterior = fim;
    fim->proximo = novo_no;
    lista->inicio->anterior = novo_no;
  }
}























