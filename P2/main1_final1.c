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
        fila->data[i] = -1; //identifica posições vazias
    }
}

// função size removida

void add(FCirc *fila, int n) {
 /*
    if (fila->tam == 0) 
        fila->s = fila->t = fila->tam = 0 ;//OBS6 */
    if((fila->t+1) % (fila->K) == fila->s) {
        fila->s = (fila->s+1) % fila->K;
        fila->data[fila->t] = n;
        fila->t=(fila->t+1) % fila->K;
    } else {
        fila->data[fila->t] = n;
        fila->t = (fila->t+1) % fila->K;
        fila->tam++;
    }
}
 
void remover(FCirc *fila){
    if (fila->tam == 0) { //OBS4
    //if(fila->t==fila->s){ //OBS2
        printf("CLEAR\n");
    } else {
        int x= fila->data[fila->s];
        fila->data[fila->s]=-1;
        fila->s=(fila->s+1)%fila->K;
        fila->tam--;
        if(x!=-1){
            printf("%d\n", x);
        }
    }
} //OBS1
 
void increase(FCirc *fila, int inc) { //OBS3
    FCirc aux; //OBS7
    aux.K = fila->K + inc;
    aux.s = fila->s; //i
    aux.t = fila->s; //j
    aux.data = calloc(aux.K, sizeof(int)); //ou calloc
     if (fila->t > fila->s) {
        while(aux.s != aux.t) { //troca
            aux.data[aux.t] = fila->data[aux.s];
            aux.s = (aux.s + 1) % fila->K;
            aux.t = (aux.t + 1) % aux.K;
        }
     }
     else if (fila->t < fila->s) { //há duas situações
        if ((fila->K - fila->s) < fila->t ) {
            aux.t = fila->s + inc;
            while (aux.s != fila->t) { //troca
                aux.data[aux.t] = fila->data[aux.s];
                aux.s = (aux.s + 1) % fila->K;
                aux.t = (aux.t + 1) % aux.K;
            }
            fila->s = fila->s + inc;
        }
        else if ((fila->K - fila->s) >= fila->t) {
            while(aux.s != fila->t) { //troca
                aux.data[aux.t] = fila->data[aux.s];
                aux.s = (aux.s + 1) % fila->K;
                aux.t = (aux.t + 1) % aux.K;
            }
        }
     }
     free(fila->data);
     fila->K = aux.K;
     fila->data = aux.data;
     fila->t = aux.t;
}
 
void list(FCirc *fila) {
    if (fila->tam == 0) { //OBS4
    // if(fila->t-1==fila->s){ //OBS2
        printf("EMPTY"); //OBS5
    } else {
        int i=fila->s;
        do {
            printf("%d ", fila->data[i]);
            i=(i+1)%fila->K;
        } while(i!=fila->t);
    }
    printf("\n");
} //OBS1
 
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


//OBS1 - adicionar um "pula linha" \n depois da saída da função 
//OBS2 - a comparação entre t-1 == s, não t = s 
//     - isso pode não funcionar (funcionou com t == s no GDB, mas no terminal foi t-1 == s)
//OBS3 - refeita inteira a função increase 
//OBS4 - por estar dando muito problema a comparação entre t e s entre diferentes compiladores, troquei por fila->tam == 0
//OBS5 - como vai ter o \n no final da funcao, tira da declaracao EMPTY
//OBS6 - quando estiver vazio, reinicia a posicao de insercao do proximo elemento (no zero)
//OBS7 - tentei criar um vetor e ir, mas foi melhor com uma outra FCirc

