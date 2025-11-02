// RECURSÃO

/* Lógica da recursividade:
    se a isntância em questão é pequena, 
      resolva-a diretamente (use força bruta se necessário)
    senão,
      reduza-a a uma instância menor do mesmo problema, 
      apllique-o o método a intância menor,
      volte a instancia original
*/

/* Dois Elementos Essenciais:
    Caso Base - condição que encerra a recursão
    Passo Recursivo - redução do problema em direção ao caso base
*/

// Definição Matemática: n! = n x (n-1)!, com 0! = 1
int fatorial(int n) {
  // Caso Base
  if (n == 0) return 1;
  // passo recursivo
  return n * fatorial (n-1);
}

// Definição: Dado um vetor de números com tamanho n, encontrar o máximo elemento
int max(int *V, int n) {
  if (n == 1) return V[0];
  int max = max[V+1, n-1]; // "V", por ser endereço na função, precisa colocar V+1 para retornar V[0+1] --- ai, dentro da recursividade, quando entramos em V+1, teremov V[1+1] = V[2]
  if (V[0] >= max) return V[0]; 
  return max;

// TORRE DE HANOI
void Hanoi(int n, char orig, char dest, char aux) {
  if (n > 0) {
    hanoi(n-1, orig, aux, dest);
    printf("move de %c para %c\n", orig, dest);
    hanoi(n-1, aux, dest, orig);
  }
}

// REGISTRO DE ATIVAÇÃO - variáveis locais + endereço de retorno após a chamada
// PILHA DE EXECUÇÃO (pilha de chamadas) - pilha dos registros de ativação das várias chamadas em execução em um programa

/* RECURSÃO DE CAUDA
Se o último passo de uma função f(x) é o retorno de f(y) então
    podemos reiterar a função f(x) usando x = y
    usando um while
    até chegar em uma das bases de recursão
*/

/* BUSCANDO UM ELEMENTO EM UMA LISTA LIGADA

No busca_rec(No lista, int x) {
  if (lista == NULL || lista->dado == x) 
    return lista;
  else 
    return busca_rec(lista->prox, x);
}

recursão é a últim linha antes do retorno da função
exceto na base, o retorno não depene do valor das variáveis locais, depende apenas do valor de retorno da chamada recursiva
*/

/* ELIMINAÇÃO DE RECURSIVA
No busca_rec(No lista, int x) {
  if (lista == NULL || lista->dado == x) 
    return lista;
  else 
    return busca_rec(lista->prox, x);
}

No busca_iterativa(No lista, int x) {
  while (lista != NULL && lista->dado != x) 
    lista = lista->prox;
  return lista;
}
*/

// recursOes que não são de cauda podem ser eliminadas, porém é necessário utilizar uma pilha e o processo é mais trabalhoso



// RECURSÃO
// Exemplo prático: FIBONACCI
    // F(n) = F(n-1) + F(n-2), com valores iniciais F1 = 1; F2 = 1
/* 
Função fib(n) 
  se n < 2 então 
    retorne n;
  caso contrário
    retorne fib(n-1) + fib(n-2);
*/

















