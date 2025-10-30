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
