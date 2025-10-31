//ORIGINAL
//TESTE 1 - ele lê os valores mas não faz a troca de lugares corretamente

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

//ALTERAÇÕES 1
// TESTE1 - não faz a troca corretamente e não lê direito
void increase(FCirc *fila, int inc) {
    int novo_K = fila->K + inc;
    fila->data = realloc(fila->data, novo_K * sizeof(int)); 
    
    if ((fila->K - fila->s) > (fila->t)) { //TODO: if: altera t; else: altera s
        for (int i = 0; i < fila->t; i++) {
             fila->data[(fila->K+inc)%(novo_K)] = fila->data[i]; 
            }
        fila->t = fila->t--; //TODO: precisa fazer modulo de t (pode dar neg)
    } else { //TODO: for (colocar na frente)
         fila->s++; 
         fila->t++;
    }
    fila->K = novo_K;
}

// ALTERAÇÕES 2
// TESTE1 - troca as posições corretamente mas não lê todos os valores direito 
// 0 no judge

void increase(FCirc *fila, int inc) { //OBS3
    fila->K += inc; 
    // fila->data = malloc(fila->K * sizeof(int)); 
    fila->data = realloc(fila->data, fila->K * sizeof(int)); //OBS7
 
    if ((fila->K - fila->s) > (fila->t)) {
        for (int i = 0; i < fila->t; i++) {
             fila->data[(fila->K+i)%(fila->K+1)] = fila->data[i];
             fila->t--;
        }
    } else {
         fila->s++;
         fila->t++;
    }
} 

// ALTERAÇÕES 3
// TESTE1 - troca as posições corretamente mas falha no print depois do segundo increase
// 10 (1/10) no judge - alguns casos estão dando runtime error (2/10) 
void increase(FCirc *fila, int inc) { //OBS3
    fila->K += inc; 
    fila->data = realloc(fila->data, fila->K * sizeof(int)); //OBS7
    
    if ((fila->K - fila->s) > (fila->t)) { //TODO: if: altera t; else: altera s
        for (int i = 0; i < fila->t; i++) {
             fila->data[(fila->K-inc+i)%(fila->K+inc)] = fila->data[i]; //mudou 
            }
            fila->t--; //TODO: precisa fazer modulo de t (pode dar neg)
    } else { //TODO: for (colocar na frente)
        fila->s++; 
    }
}
