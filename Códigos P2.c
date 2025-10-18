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

// ----------------------------------------------------------------------------------------
// PILHAS

// Criar pilha
typedef struct {
  int *data;
  int topo;
  int capacidade;
} Pilha;

// Adicionar algum dado a pilha
