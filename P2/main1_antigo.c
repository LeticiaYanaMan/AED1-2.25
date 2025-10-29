#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct{
    int *data;
    int t;
    int s;
    int K;
    int tam;
} FCirc;
 
void init_fila(FCirc *fila, int K) {
    fila->K = K; 
    fila->data = (int *)malloc(fila->K * sizeof(int));
    fila->s = fila->t=fila->tam=0;
    for(int i = 0; i < fila->K; i++){
        fila->data[i] = -1;
    }
}
 
int size(FCirc *fila){
    if(fila->t >= fila->s){
        return fila->t - fila->s;
    } else {
        return fila->K - fila->s + fila->t;
    }
}
 
void add(FCirc *fila, int n){
    if((fila->t+1)%(fila->K)==fila->s){
        fila->s=(fila->s+1)%fila->K;
        fila->data[fila->t]=n;
        fila->t=(fila->t+1)% fila->K;
    } else {
        fila->data[fila->t]=n;
        fila->t=(fila->t+1)%fila->K;
        fila->tam++;
    }
}
 
void remover(FCirc *fila){
    if(fila->t==fila->s){
        printf("CLEAR\n");
    } else {
        int x= fila->data[fila->s];
        fila->data[fila->s]=-1;
        fila->s=(fila->s+1)%fila->K;
        fila->tam--;
        if(x!=-1){
            printf("%d", x);
        }
    }
}
 
void increase(FCirc *fila, int inc){
    int novo_K = fila->K + inc;
    int *novo_data=(int*)malloc(novo_K*sizeof(int));
    
    int tam = size(fila);
    
    for(int i=0; i <fila->tam; i++){
        novo_data[i] = fila->data[(fila->s+i)%fila->K];
    }
    
    for(int i = fila->tam; i < novo_K; i++){
        novo_data[i] = -1;
    }
    
    free(fila->data);
    fila->data = novo_data;
    fila->K = novo_K;
    fila->s = 0; 
    fila->t = fila->tam; 
}
 
void list(FCirc *fila){
    if(fila->t==fila->s){
        printf("EMPTY/n");
    } else {
        int i=fila->s;
        do {
            printf("%d ", fila->data[i]);
            i=(i+1)%fila->K;
        } while(i!=fila->t);
    }
}
 
void print(FCirc *fila){
    for(int i=0 ; i<fila->K ; i++){
        int cheio=0;
        if(fila->tam>0){
            int dist = (i-(fila->s)+fila->K)%fila->K;
            if(dist<fila->tam){
                cheio=1;
            }
        }
        if(cheio){
            printf("%d", fila->data[i]);
        } else {
            printf("-");
        }
        if(i<fila->K-1){
            printf(" ");
        }
    }
    printf("\n");
}
 
void end(FCirc *fila){
    free(fila->data);
    free(fila);
}
 
int main(){
    int K,n, inc;
    FCirc *fila;
    scanf("%d", &K);
    fila = (FCirc*)malloc(sizeof(FCirc)); 
    init_fila(fila, K);
    char com[50];
    while(scanf("%s", com)!=EOF){
        if(strcmp(com, "ADD")==0){
            scanf("%d", &n);
            add(fila,n);
        } else if(strcmp(com, "REMOVE")==0)
            remover(fila);
        else if(strcmp(com, "LIST")==0)
            list(fila);
        else if(strcmp(com, "PRINT")==0)
            print(fila);
        else if(strcmp(com, "INCREASE")==0) {
            scanf("%d", &inc);
            increase(fila, inc);
        } else if(strcmp(com, "END")==0){
            end(fila);
            break;
        }
    }
    return 0;
}
