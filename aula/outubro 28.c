// STRUTURA DE UM NÓ

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
// primeiro: cabeça

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

// ESTUDAR UM FIBONACCI ASSIM

















  







