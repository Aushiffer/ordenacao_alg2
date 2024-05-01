#include "ordenacao.h"

void getNome(char nome[]) {
	// substitua por seu nome
	strncpy(nome, "Caio Eduardo Ferreira de Miranda", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME - 1] = '\0';  // adicionada terminação manual para caso de overflow
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20232359; }

ssize_t buscaSequencial(int vetor[], size_t tam, int valor, 
			uint64_t* numComparacoes) {

	for (size_t i = 0; i < tam; i++) {
		(*numComparacoes)++;
		
		if (vetor[i] >= valor)
			return i;
	}
    	
	return -1;
}

ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor, 
			uint64_t* numComparacoes) {
	
	if (tam <= 0)
		return -1;

	(*numComparacoes)++;

	if (vetor[tam - 1] <= valor)
		return tam - 1;
	
	return buscaSequencialRec(vetor, tam - 1, valor, numComparacoes);
}

ssize_t buscaBinaria(int vetor[], size_t tam, int valor, 
			uint64_t* numComparacoes) {
	
	ssize_t a = 0;
	ssize_t b = tam - 1;
	ssize_t m = b / 2;

	while (a <= b) {
		(*numComparacoes)++;

		if (vetor[m] > valor)
			b = m - 1;
		else
			a = m + 1;

		m = (a + b) / 2;
	}

	return a - 1;
}

ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor, 
			uint64_t* numComparacoes) {

	return buscaBinRecWrapper(vetor, 0, tam - 1, valor, numComparacoes);
}

uint64_t insertionSort(int vetor[], size_t tam) {
	u_int64_t nComps = 0;

	for (size_t i = 0; i < tam; i++) {
		size_t k = i;
		nComps++;

		while (k > 0 && vetor[k] < vetor[k - 1]) {
			nComps++;
			troca(vetor, k, k - 1);
			k--;
		}
	}
    
    	return nComps;
}

uint64_t insertionSortRec(int vetor[], size_t tam) {
	u_int64_t nComps = 0;
	insSortRecWrapper(vetor, 0, tam, &nComps);
    	
	return nComps;
}

uint64_t selectionSort(int vetor[], size_t tam) {
	u_int64_t nComps = 0;

	for (size_t i = 0; i < tam; i++) {
		size_t min = i;

		for (size_t j = i + 1; j < tam; j++) {
			nComps++;

			if (vetor[j] < vetor[min])
				min = j;
		}

		/* Se o menor já não estiver na i-ésima posição */
		if (min != i)
			troca(vetor, min, i);
	}
	
	return nComps;
}

uint64_t selectionSortRec(int vetor[], size_t tam) {
	u_int64_t nComps = 0;
	selSortRecWrapper(vetor, 0, tam, &nComps);

	return nComps;
}

uint64_t mergeSort(int vetor[], size_t tam) {
	u_int64_t nComps = 0;
	mergeSortWrapper(vetor, 0, tam - 1, &nComps);
	
	return nComps;
}
