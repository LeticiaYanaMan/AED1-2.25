/* 
  RECURSÃO - quebra o codigo em partes pequenas
  mais cara computacionalmente
*/

/* 
se a instancia em questão é pequena,
  resola-a diretamente (use força bruta se necessário)
senão
  reduz a instância menor do mesmo problema
    aplique o metodo a instancia menor
    volte a instancia original
*/

/* DEFINIÇÃO MATEMATICA -
      n! = n x (n-1)!, com 0! = 1
        5! = 5 x 4! = 5 x 4 x 3! = 5 x 4 x 3 x 2! = 5 x 4 x 3 x 2 x 1! = 5 x 4 x 3 x 2 x 1 x 0!
        0! = 1 portanto 1! = 1 portanto 2! = 2 prontanto 3! = 6 portanto 4! = 24 portanto 5! = 120
  segue uma dinâmica de PILHA - começa a desempilhar pelo caso base (no nosso caso, 0! = 1)

int fatorial(int n) {
  if (n == 0) return 1;
  return n * fatorial(n-1);
}
*/

/* 
int max(int *V, int n) {
  if (n == 1) return V[0];
  int max = max[V+1, n-1]; // "V", por ser endereço na função, precisa colocar V+1 para retornar V[0+1] --- ai, dentro da recursividade, quando entramos em V+1, teremov V[1+1] = V[2]
  if (V[0] >= max) return V[0]; 
  return max;
}
*/

/* quantidade de movimenos na torre de hanoi
int hanoi(int n) {
  if (n == 1) return 1;
  return 2* hanoi(n-1) +1;
}

int main() {
  int N;
  scanf("%d", &N) {
  printf("%d\n", hanoi(n));
  } 
  */

