#include "aux.h"

void troca(int vetor[], size_t a, size_t b) {
        int aux = vetor[a];
        vetor[a] = vetor[b];
        vetor[b] = aux;
}

void preencheVetorAleat(int vetor[], size_t tam) {
        size_t randLim;
        printf("\nEntre com o valor aleatório máximo admitido dentro do vetor: ");
        scanf("%lu", &randLim);
        getchar();

        for (size_t i = 0; i < tam; i++)
                vetor[i] = rand() % randLim;
}

void preencheVetorCresc(int vetor[], size_t tam) {
        for (size_t i = 0; i < tam; i++)
                vetor[i] = (int)i;
}

void preencheVetorDecresc(int vetor[], size_t tam) {
        for (size_t i = 0; i < tam; i++)
                vetor[i] = (int)(tam - i - 1);
}

void printVetor(int vetor[], size_t tam) {
        for (size_t i = 0; i < tam; i++)
                printf("%d ", vetor[i]);

        printf("\n");
}