#ifndef __WRAPPER__
#define __WRAPPER__

/* Este .h contém todos os includes necessśarios para o funcionamento do programa */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>
#include "aux.h"

/* Funções wrapper para as funções recursivas */

ssize_t buscaBinRecWrapper(int vetor[], ssize_t a, ssize_t b, 
                        int val, u_int64_t *nComps);

void insSortRecWrapper(int vetor[], size_t a, size_t b, 
                        uint64_t *nComps);

void selSortRecWrapper(int vetor[], size_t a, size_t b, 
                        u_int64_t *nComps);

void mergeSortWrapper(int vetor[], size_t a, size_t b, 
                        u_int64_t *nComps);

/* Intercalação usada para fazer o Merge Sort (baseada na função do livro do Cormen) */
void merge(int vetor[], size_t a, size_t b, 
                        size_t m, u_int64_t *nComps);

#endif // __WRAPPER__