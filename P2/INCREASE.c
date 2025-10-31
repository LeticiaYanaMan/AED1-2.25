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

// ALTERAÇÕES 3 - tirou o fila->t-- de dentro do for
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


// ALTERAÇÕES 4
// TESTE1 - faz tudo certo, só que ao inves de adicionar 50, adiciona 40 (??)

void increase(FCirc *fila, int inc) { //OBS3
    int novo_K = fila->K + inc; 
    fila->data = realloc(fila->data, novo_K * sizeof(int)); //OBS7
    
    if ((novo_K - fila->s) > (fila->t)) { //TODO: if: altera t; else: altera s
        for (int i = 0; i < fila->t; i++) {
             fila->data[(fila->K+i)%(novo_K)] = fila->data[i]; //mudou 
            }
            fila->t = novo_K; //TODO: precisa fazer modulo de t (pode dar neg)
    } else { //TODO: for (colocar na frente)
        fila->s++; 
    }
    fila->K = novo_K;
}

// ALTERAÇÕES 5


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












