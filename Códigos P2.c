#include <stdio.h>

// Endereços e Ponteiros (Apêndice D)
// Exercício D.3.2
void hm(int t, int *h, int *m) { //declara que vai receber uma variavel inteira e DOIS ENDEREÇOS
	*h = t/60; // note que fica com o asterisco porque ainda está falando do que vai ir dentro do endereço
	*m = t%60;
}

int main () {
	int t = 600;
	int h;
	int m; //declara como variavek normal
	hm(t, &h, &m); //como declarou que iria receber (int *h), na hora de usar, coloca (&h)
	printf("horas = %d, minutos = %d\n", h, m);
	return 0;
}

// Exercício D.3.3
void mm(int *v, int n, int *min, int *max) {
	*min = v[0]; // o vetor é criado como um ponteiro (*v) - quando for usar (no main), só coloca o nome do vetor
	*max = v[0]; //como é vetor, não precisa colocar *v[0], masta v[0]
	for (int i = 0; i < n; i++) {
		if (v[i] < *min) {
			*min = v[i];
		}
		else {
			if (v[i] > *max) {
				*max = v[i];
			}
		}
	}
}

int main() {
	int vet[5];
	for (int i = 0; i < 5; i++) {
	    scanf("%d", &vet[i]);
	}
	int min;
  int max;
	mm(vet, 5, &min, &max);
	printf("minimo = %d, maximo = %d", min, max);
	return 0;
}

// Anotações importante sobre ponteiros, vetores e tal
  // Ex. D.4.1 ---- "v + 3" é igual a v[3]

  // D.4.3 
  	// int v[100], k;  quais são as operações para: &v[k+9]
		// k é menor que 90, ou ultrapassará o limite do vetor. 
		// Criaremos um ponteiro (*p) que apontará o endereço v + k (ou seja, endereço de v[k]). 
		// Depois, faremos *p + 9, indicando que queremos 9 “casas” depois da variavel v[k], ou seja, v[k + 9].

  // data *p; data x; p = *x; 	p->dia = 31 equivale a x.dia = 31 e a (*p).dia = 31	
  // printf("%d", *p) vai imprimir o que p está apontando ; printf("%d", &p) vai imprimir o endereço de p; 
		//printf("%d", p) vai imprimir o endereço da variavel para a qual p aponta


// ----------------------------------------------------------------------------------------
// Alocação Dinâmica de memória (Apêndice F)

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf(”%d”, &n);
	int *v;
	v = malloc(n * sizeof(int)); // cria um vetor dinâmico com memoria n * int
	for (int i = 0; i < n; i++) {
		scanf(“%d”, &v[i]);
	}
	for (int i = n; i > 0; i- -) {
		printf(“%d”, v[i-1]); // imprime os números inseridos inversamente
	}
	return 0;
}

// ----------------------------------------------------------------------------------------
// PILHAS - Capítulo 6

// Criar pilha
typedef struct {
  int *data;
  int topo;
  int capacidade;
} Pilha;

// Inicializar a pilha
void init(Pilha *pilha, int capacidade) {
	pilha->data = (int *)malloc(capacidade * sizeof(int)); // o (int *) e sizeof(int) 
		// esse int precisa condizer com a sua variavel data --- se *data for declarado como char, precisa trocar tudo por char
	pilha->topo = -1;
	pilha->capacidade = capacidade;
}

// Adicionar algum dado a pilha --- p[t++] = x
void inserir(Pilha *pilha, int x) {
	if (pilha->topo == pilha->capacidade - 1) { // se o topo for equivalente a capacidade -1, ou seja, se estiver cheia
		pilha->capacidade *= 2; //duplica a capacidade da pilha
		pilha->data = (int *)realloc(pilha->data, pilha->capacidade * sizeof(int)); // realloc(o que vai realocar, quanto precisa ser realocado)
	}
 	pilha->data[++pilha->topo} = valor;
}
			// coloca que precisa realocar pilha->capacidade *sizeof(int) porque os dados estão armazenados como int

// Remover algum dado da pilha --- x = p[--t];
int remover(Pilha *pilha) { // o tipo de dado que vai sair no return precisa combinar com o tipo de *data declarado
		return pilha->data[pilha->t--]; //mesma logica do x = p[t--]
			// x equivale ao return e p[t--] equivale a pilha->data[aqui vem o topo (t) --]

// 6.1.2 exercicio de inverter uma frase --- não do jeito que pede no enunciado mais foi o que consegui fazer

#include <stdio.h>
#include <string.h>

int main() {
	Pilha *pilha;
	char frase[1001];
	fgets(frase, sizeof(frase), stdin); //quando for ler string, da o fgets
	int size = strlen(frase); // para ver o tamanho da string, usa strlen
	init(pilha, size);
	inserir(pilha, frase, size);
	char letra;
	for (int i = 0; i < size; i++) {
		letra = remover(pilha);
		printf("%c", letra);
	}
	
	free(pilha->data); // SEMPRE LEMBRE DE DAR O FREE 
	return 0;
}

// notação pósfixa 
// A B C D E F - * - G H * - * + I 3 - equivale a A + B * (C - (D * (E - F)) - (G * H)) - I * 3

// Ex. 6.3.1 ---> (A + B) * D + E / (F + A * D) + C
		// ( (A + B) * D) + ( E / (F + (A * D) ) ) + C  
		//	 A B + D * E F A D * + C + / + 
		// 	((A + B) * D) + E / (F + A * D) + C

// ----------------------------------------------------------------------------------------
// FILAS - Capítulo 5

// criação de uma estrutura de fila
typedef struct { 
	int *data;
	int t; // topo da fila
	int s; // primeiro da fila
	int cap; // capacidade máxima da fila
} Fila;

// insere um valor na fila
void insert(int x, int s, int *t) { // insere o valor x - *s é começo e t é final
	if ((*t + 1) % cap != s) { // se a fila não está cheia (considerando o espaço vaz
		fila[*t] = x; // vai adicionar 
		*t = (*t+1) % cap; // vai alterar o valor do final
	}
}

// remove um valor da fila
int remove(int *s, int t) { // *s é a primeira posição e t é a última
	int x = -1;
	if (*s != t) { //se a fila não está vazia
		x = fila[*s++]; // retirar o valor e alterar a posição *s
		if (*s == cap) *s = 0; // volta para o início, indica que encheu  
	}
	return x; // se a fila estiver vazia, vai retornar -1
}

// Fila Circular 
void FilaCircular(Fila *fila) {
	int novaCapacidade = fila->cap + 5; // aumenta o valor que indica a capacidade
	int *novaData = malloc(novaCapacidade * sizeof(int)); // cria num novo vetor com tamanho da fila nova

	int j = 0;
	for (int i = fila->s; i = fila->t; i = (i +1) % fila->cap) {
		novaData[j++] = fila->data[i]; // transfere os dados da fila anterior
	}
	free(fila->data);
	fila->data = novaData; // tranforma essa nova lista na que a gente acessa com *fila
	fila->s = 0; // tranforma essa nova lista na que a gente acessa com *fila
	fila->t = j; // tranforma essa nova lista na que a gente acessa com *fila
	fila->cap = novaCapacidade; // tranforma essa nova lista na que a gente acessa com *fila
}
//MALU - filas circulares
typedef struct{
    int *itens;
    int s; // indice do primeiro elemento
    int t; //indice do ultimo elemento +1
    int N; //capacidade da fila
} fila;

void insert(fila *fila, int y){ 
    if((fila->t+1)%fila->N==fila->s){ 
        printf("Cheia");
        return;
    } 
    fila->itens[fila->t]=y;
    fila->t=(fila->t+1)%fila->N;
}

int remove(fila *fila){ 
    int x=-1;
    if(fila->s!=fila->t){ //nao ta vazia
        x=fila->itens[fila->s++];
        if(fila->s==fila->N){
            fila->s=0;
        }
    }
    return x;
}

// ----------------------------------------------------------------------------------------
// ARQUIVOS 

//normal - ler
FILE *file = fopen("data.txt", "r");
//normal - escrever
FILE *file = fopen("data.txt", "w");
// escrever dados
fprintf(file, "Nome: %s, Idade: %d\n", "Alice", 25);
// ler dados
fscanf(file, "%s %d", name, &age);

// binário - ler
FILE *file = fopen("data.txt", "rb");
// binário - escrever
FILE *file = fopen("data.txt", "wb");
// binario - escrever dados
fwrite(&a1, sizeof(student), 1, file);
// binario - ler dados
fread(&a1, sizeof(student), 1, file); // em fwrite e em fread, considere que temos "student a1"

//fechar arquivo
fclose(file);







