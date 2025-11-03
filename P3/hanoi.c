#include <stdio.h>
#include <stdlib.h>

void hanoi(int d, char og, char meio, char fim){
  if(d==1){
    printf("Move de %d para %d", og, fim);
    return;
  }
  else {
    hanoi(d-1, og, meio, fim); //para mover da torre A para B, tendo C como intermediario
    printf("Move o disco %d de %c para %c", d, og, fim);
    hanoi(d-1, meio, og, fim); //move de B para C, agora A esta no meio
  }
}

int main(){
  int n;
  scanf("%d", &n);
  hanoi(n, 'A', 'B', 'C');
  printf("/n");
}  
