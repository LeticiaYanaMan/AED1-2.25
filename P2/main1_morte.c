#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Definição da estrutura da Fila Circular (FCirc)
typedef struct {
    int *data;      // Ponteiro para o array de dados
    int s;          // 'head' - Índice do elemento mais antigo (início da fila)
    int t;          // 'tail' - Índice da próxima posição de inserção (fim da fila)
    int K;          // Capacidade máxima atual do array
    int tam;        // Número atual de elementos na fila
} FCirc;
 
/**
 * Inicializa a Fila Circular com capacidade K.
 */
void init_fila(FCirc *fila, int K) {
    fila->K = K; 
    // Aloca o array de inteiros
    fila->data = (int *)malloc(fila->K * sizeof(int));
    if (fila->data == NULL) {
        // Tratamento de erro de alocação
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    
    // Inicializa índices e tamanho
    fila->s = fila->t = fila->tam = 0;
    
    // Preenche o array com -1 para identificar posições vazias (requisito PRINT)
    for(int i = 0; i < fila->K; i++){
        fila->data[i] = -1;
    }
}
 
/**
 * Adiciona o número n ao final do log. Se o log estiver cheio,
 * [span_0](start_span)o evento mais antigo é substituído (comportamento Circular Buffer)[span_0](end_span).
 */
void add(FCirc *fila, int n) {
    // Insere o novo elemento na posição 't'
    fila->data[fila->t] = n; 

    // Verifica se a fila estava cheia (tam == K)
    if (fila->tam == fila->K) { 
        // O elemento mais antigo (em 's') foi substituído. O 's' precisa avançar.
        fila->s = (fila->s + 1) % fila->K;
        // O tamanho (tam) permanece K
    } else {
        // Se não estava cheia, o tamanho aumenta.
        fila->tam++;
    }

    // Avança o índice de inserção 't'
    fila->t = (fila->t + 1) % fila->K;
}
 
/**
 * [span_1](start_span)Remove o evento mais antigo da fila[span_1](end_span).
 * [span_2](start_span)Imprime o valor removido ou "CLEAR" se vazia[span_2](end_span).
 */
void remover(FCirc *fila) {
    if (fila->tam == 0) { 
        printf("CLEAR\n");
    } else {
        int x = fila->data[fila->s];
        
        // Marca a posição como vazia para a função PRINT
        fila->data[fila->s] = -1; 
        
        fila->s = (fila->s + 1) % fila->K; // Avança o início
        fila->tam--; // Diminui o tamanho
        
        printf("%d\n", x); 
    }
} 
 
/**
 * [span_3](start_span)Aumenta a capacidade K da fila para K = K + inc[span_3](end_span).
 * [span_4](start_span)Otimiza o incremento movendo os elementos para o início do novo array[span_4](end_span).
 */
void increase(FCirc *fila, int inc) { 
    int K_antigo = fila->K;
    int K_novo = K_antigo + inc;
    
    // 1. Realoca o array para o novo tamanho K_novo
    // Usar realloc preserva os dados existentes
    int *novo_data = (int *)realloc(fila->data, K_novo * sizeof(int));
    if (novo_data == NULL) {
        perror("Erro ao realocar memória");
        return; 
    }
    fila->data = novo_data;
    fila->K = K_novo;
    
    // 2. Otimização: Mover elementos para o início do novo array
    if (fila->tam > 0) {
        if (fila->s >= fila->t) { 
            // Caso "quebrado": [D E - A B C] s > t
            
            // a) Move a primeira parte (de 's' até K_antigo-1) para o novo índice 0
            int p1_size = K_antigo - fila->s;
            // Usa memmove para lidar com possível sobreposição (se a realocação for "in-place")
            memmove(fila->data, &fila->data[fila->s], p1_size * sizeof(int));

            // b) Move a segunda parte (de 0 até 't'-1) para o final da primeira parte
            int p2_size = fila->t;
            memmove(&fila->data[p1_size], &fila->data[0], p2_size * sizeof(int));
            
            // Atualiza os índices da fila para o novo layout (sempre começando em 0)
            fila->s = 0;
            fila->t = p1_size + p2_size;
            
        } else {
            // Caso "contínuo": [A B C D E - - -] s < t (ou s=0)
            // Os elementos já estão no início. O novo 't' permanece o mesmo.
            // Apenas atualizamos a posição de 't' se necessário, mas como não houve
            // cópia para posições diferentes, 's' e 't' permanecem válidos.
        }
    }
    
    // 3. Inicializar as novas posições (do novo 't' até K_novo-1) como vazias (-1)
    for (int i = fila->t; i < K_novo; i++) {
        fila->data[i] = -1;
    }
}
 
/**
 * [span_5](start_span)Imprime os eventos no log, do mais antigo para o mais recente[span_5](end_span).
 */
void list(FCirc *fila) {
    if (fila->tam == 0) { 
        printf("EMPTY\n"); [span_6](start_span)//[span_6](end_span)
    } else {
        int i=fila->s;
        do {
            printf("%d", fila->data[i]);
            i=(i+1)%fila->K;
            if (i != fila->t) {
                printf(" "); // Imprime espaço apenas entre elementos
            }
        } while(i!=fila->t);
        printf("\n");
    }
} 
 
/**
 * [span_7](start_span)Imprime todo o vetor atual do log, da posição 0 até K-1[span_7](end_span).
 * [span_8](start_span)Imprime '-' para registros vazios[span_8](end_span).
 */
void print(FCirc *fila) {
    for(int i=0 ; i<fila->K ; i++){
        if(fila->data[i]!=-1){
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
 
/**
 * Libera a memória alocada.
 */
void end(FCirc *fila) {
    if (fila->data != NULL) {
        free(fila->data);
    }
    free(fila);
}
 
int main() {
    int K, n, inc;
    FCirc *fila;
    
    if (scanf("%d", &K) != 1) return 0; [span_9](start_span)// Lê K[span_9](end_span)
    
    fila = (FCirc*)malloc(sizeof(FCirc)); 
    if (fila == NULL) {
        perror("Erro ao alocar fila");
        return 1;
    }
    
    init_fila(fila, K);
    char com[50];
    
    [span_10](start_span)// Loop de leitura de comandos[span_10](end_span)
    while(scanf("%s", com)!=EOF){
        if(strcmp(com, "ADD")==0){
            if (scanf("%d", &n) == 1) add(fila, n); [span_11](start_span)//[span_11](end_span)
        } else if(strcmp(com, "REMOVE")==0) {
            remover(fila); [span_12](start_span)//[span_12](end_span)
        } else if(strcmp(com, "LIST")==0) {
            list(fila); [span_13](start_span)//[span_13](end_span)
        } else if(strcmp(com, "PRINT")==0) {
            print(fila); [span_14](start_span)//[span_14](end_span)
        } else if(strcmp(com, "INCREASE")==0) {
            if (scanf("%d", &inc) == 1) increase(fila, inc); [span_15](start_span)//[span_15](end_span)
        } else if(strcmp(com, "END")==0){
            end(fila); [span_16](start_span)//[span_16](end_span)
            break;
        }
    }
    return 0;
}
