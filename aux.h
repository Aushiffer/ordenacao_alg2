#ifndef __AUX__
#define __AUX__

#include "wrapper.h"

/* Troca vetor[a] e vetor[b] */
void troca(int vetor[], size_t a, size_t b);

/* Preenche o vetor com valores aleatórios */
void preencheVetorAleat(int vetor[], size_t tam);

/* Preenche o vetor com valores sempre crescentes */
void preencheVetorCresc(int vetor[], size_t tam);

/* Preenche o vetor com valores sempre decrescentes */
void preencheVetorDecresc(int vetor[], size_t tam);

/* Imprime o vetor */
void printVetor(int vetor[], size_t tam);

#endif // __AUX__