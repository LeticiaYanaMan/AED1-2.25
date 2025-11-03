#include <stdio.h>
#include <stdlib.h>

void hanoi(int d, int og, int meio, int fim){
  if(d==1){
    printf("Move de %d para %d", hanoi(og, fim));
  }
  else {
    hanoi(d-1, og, meio, fim); //para mover da torre A para B, tendo C como intermediario
    printf("Move o disco %d de %d para %d", n, og, fim);
    hanoi(d-1, meio, og, fim); //move de B para C, agora A esta no meio
  }

int main(){
  int n;
  scanf("%d", &n);
  hanoi(n, '1', '2', '3');
  printf("/n");
}  
