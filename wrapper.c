#include "wrapper.h"

ssize_t buscaBinRecWrapper(int vetor[], ssize_t a, ssize_t b, 
                        int val, u_int64_t *nComps) {
        
        if (a > b)
                return a - 1;

        ssize_t m = (a + b) / 2;
        (*nComps)++;

        if (vetor[m] > val)
                return buscaBinRecWrapper(vetor, a, m - 1, val, nComps);

        return buscaBinRecWrapper(vetor, m + 1, b, val, nComps);
}

void insSortRecWrapper(int vetor[], size_t a, size_t b, 
                        u_int64_t *nComps) {
        
        if (a >= b)
                return;
        
        insSortRecWrapper(vetor, a, b - 1, nComps);
        size_t k = b - 1;
        (*nComps)++;

        while (k > a && vetor[k] < vetor[k - 1]) {
                (*nComps)++;
                troca(vetor, k, k - 1);
                k--;
        }
}

void selSortRecWrapper(int vetor[], size_t a, size_t b, 
                        u_int64_t *nComps) {

        if (a >= b)
                return;

        size_t min = a;

        for (size_t i = a + 1; i < b; i++) {
                (*nComps)++;

                if (vetor[i] < vetor[min])
                        min = i;
        }

        if (min != a)
                troca(vetor, min, a);

        selSortRecWrapper(vetor, a + 1, b, nComps);
}

void merge(int vetor[], size_t a, size_t b, 
                        size_t m, u_int64_t *nComps) {
        
        size_t tamEsq = m - a + 1;
        size_t tamDir = b - m;
        int *L = (int *)malloc(tamEsq * sizeof(int));

        if (!L) {
                fprintf(stderr, "[-] merge(): falha na alocação do vetor auxiliar (L)\n");

                return;
        }

        int *R = (int *)malloc(tamDir * sizeof(int));

        if (!R) {
                fprintf(stderr, "[-] merge(): falha na alocação do vetor auxiliar (R)\n");
                free(L);
                L = NULL;

                return;
        }

        for (size_t i = 0; i < tamEsq; i++)
                L[i] = vetor[a + i];
        
        for (size_t j = 0; j < tamDir; j++)
                R[j] = vetor[m + j + 1];

        size_t i = 0, j = 0, k = a;

        while (i < tamEsq && j < tamDir) {
                (*nComps)++;

                if (L[i] <= R[j]) {
                        vetor[k] = L[i];
                        i++;
                } else {
                        vetor[k] = R[j];
                        j++;
                }

                k++;
        }

        while (i < tamEsq) {
                vetor[k] = L[i];
                i++;
                k++;
        }

        while (j < tamDir) {
                vetor[k] = R[j];
                j++;
                k++;
        }

        free(L);
        L = NULL;
        free(R);
        R = NULL;
}

void mergeSortWrapper(int vetor[], size_t a, size_t b, 
                        u_int64_t *nComps) {

        if (a >= b)
                return;

        size_t m = a + (b - a) / 2;
        mergeSortWrapper(vetor, a, m, nComps);
        mergeSortWrapper(vetor, m + 1, b, nComps);
        merge(vetor, a, b, m, nComps);
}
