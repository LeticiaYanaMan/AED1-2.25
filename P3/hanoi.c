#include <stdio.h>
#include <stdlib.h>

void hanoi(int d, char og, char fim, char meio){
  if(d==1){
    printf("Move de %d para %d", og, fim);
    return;
  }
    hanoi(d-1, og, meio, fim); //para mover da torre A para B, tendo C como intermediario
    printf("Move o disco %d de %c para %c\n", d, og, fim);
    hanoi(d-1, meio, fim, og); //move de B para C, agora A esta no meio
}

int main(){
  int n;
  printf("Numero de discos: ");
  scanf("%d", &n);
  hanoi(n, 'A', 'B', 'C');
  printf("\n");
  return 0;
}  
