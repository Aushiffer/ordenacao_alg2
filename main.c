/* Trabalho 1 de Alg 2 - Ordenação e busca 
 * @author: Caio Eduardo Ferreira de Miranda
 * @date: 17/04/2024 */

#include "ordenacao.h"

int main() {
	char nome[MAX_CHAR_NOME];
	double tempoTotal;
	int *vetor;
	ssize_t idxBusca;
	size_t tamVetor;
	uint64_t numComp = 0;
	clock_t comeco, fim;
	srand(time(NULL));
	getNome(nome);
	printf("Trabalho de: %s\n", nome);
	printf("GRR: %u\n", getGRR());

	short select;

	do {
		printf("\nSelecione uma opção\n\n");
		printf("1: Busca\n");
		printf("2: Ordenação\n");
		printf("3: Encerrar o programa\n");
		scanf("%1hd", &select);
		getchar();

		if (select == 1 || select == 2) {
			printf("\nEntre com o tamanho do vetor a ser operado: ");
			scanf("%lu", &tamVetor);
			getchar();
			vetor = (int *)malloc(tamVetor * sizeof(int));

			if (!vetor) {
				fprintf(stderr, "[-] main(): falha na alocação do vetor\n");

				return 1;
			}
		}

		if (select == 1) {
			short selectBusca;

			do {	
				numComp = 0;
				int valBusca;
				char imprimeVetor;
				printf("\nEntre com o valor a ser buscado: ");
				scanf("%d", &valBusca);
				getchar();
				printf("\nO vetor deve ser impresso? (Pressione S para SIM) ");
				scanf("%c", &imprimeVetor);
				getchar();
				preencheVetorCresc(vetor, tamVetor);

				if (imprimeVetor == 's' || imprimeVetor == 'S') {
					printf("\nVetor: ");
					printVetor(vetor, tamVetor);
				}

				printf("\n1: Busca sequencial iterativa (ingênua)\n");
				printf("2: Busca sequencial recursiva (ingênua)\n");
				printf("3: Busca binária iterativa\n");
				printf("4: Busca binária recursiva\n");
				printf("5: Voltar ao menu anterior\n");
				scanf("%1hd", &selectBusca);
				getchar();

				if (selectBusca == 1) {
					comeco = clock();
					idxBusca = buscaSequencial(vetor, tamVetor, valBusca, &numComp);
					fim = clock();
					tempoTotal = ((double)fim - comeco) / CLOCKS_PER_SEC;

					if (idxBusca >= 0 && vetor[idxBusca] == valBusca)
						printf("\nO valor foi encontrado na posição %ld\n", idxBusca);
					else
						printf("\nO valor não foi encontrado\n");
					
					printf("Comparações: %lu\n", numComp);
					printf("Tempo de execução: %fs\n", tempoTotal);
				} else if (selectBusca == 2) {
					comeco = clock();
					idxBusca = buscaSequencialRec(vetor, tamVetor, valBusca, &numComp);
					fim = clock();
					tempoTotal = ((double)fim - comeco) / CLOCKS_PER_SEC;

					if (idxBusca >= 0 && vetor[idxBusca] == valBusca)
						printf("\nO valor foi encontrado na posição %ld\n", idxBusca);
					else
						printf("\nO valor não foi encontrado\n");
					
					printf("Comparações: %lu\n", numComp);
					printf("Tempo de execução: %fs\n", tempoTotal);
				} else if (selectBusca == 3) {
					comeco = clock();
					idxBusca = buscaBinaria(vetor, tamVetor, valBusca, &numComp);
					fim = clock();
					tempoTotal = ((double)fim - comeco) / CLOCKS_PER_SEC;

					if (idxBusca >= 0 && vetor[idxBusca] == valBusca)
						printf("\nO valor foi encontrado na posição %ld\n", idxBusca);
					else
						printf("\nO valor não foi encontrado\n");
					
					printf("Comparações: %lu\n", numComp);
					printf("Tempo de execução: %fs\n", tempoTotal);
				} else if (selectBusca == 4) {
					comeco = clock();
					idxBusca = buscaBinariaRec(vetor, tamVetor, valBusca, &numComp);
					fim = clock();
					tempoTotal = ((double)fim - comeco) / CLOCKS_PER_SEC;

					if (idxBusca >= 0 && vetor[idxBusca] == valBusca)
						printf("\nO valor foi encontrado na posição %ld\n", idxBusca);
					else
						printf("\nO valor não foi encontrado\n");

					printf("Comparações: %lu\n", numComp);
					printf("Tempo de execução: %fs\n", tempoTotal);
				} else if (selectBusca == 5) {
					free(vetor);
					vetor = NULL;
					
					break;
				} else {
					fprintf(stderr, "[-] main(): opção inválida\n");
				}
				
				free(vetor);
				vetor = NULL;
				printf("\nPressione qualquer tecla para continuar");
				getchar();

				break;
			} while (1);
		} else if (select == 2) {
			short selectOrd;

			do {
				numComp = 0;
				short selectCaso;
				char imprimeVetor;
				printf("\nO vetor antes e depois da ordenação deve ser impresso? (Pressione S para SIM) ");
				scanf("%c", &imprimeVetor);
				getchar();
				printf("\n1: Insertion Sort recursivo\n");
				printf("2: Insertion Sort iterativo\n");
				printf("3: Selection Sort recursivo\n");
				printf("4: Selection Sort iterativo\n");
				printf("5: Merge Sort\n");
				printf("6: Voltar ao menu anterior\n");
				scanf("%1hd", &selectOrd);
				getchar();

				if (selectOrd == 1) {
					printf("\n1: Vetor em ordem crescente\n");
					printf("2: Vetor em ordem decrescente\n");
					printf("3: Vetor em ordem \"aleatória\"\n");
					scanf("%1hd", &selectCaso);
					getchar();

					if (selectCaso == 1)
						preencheVetorCresc(vetor, tamVetor);
					else if (selectCaso == 2)
						preencheVetorDecresc(vetor, tamVetor);
					else
						preencheVetorAleat(vetor, tamVetor);

					if (imprimeVetor == 'S' || imprimeVetor == 's') {
						printf("\nVetor antes da ordenação: ");
						printVetor(vetor, tamVetor);
					}
					
					comeco = clock();
					numComp = insertionSortRec(vetor, tamVetor);
					fim = clock();
					tempoTotal = ((double)fim - comeco) / CLOCKS_PER_SEC;

					if (imprimeVetor == 'S' || imprimeVetor == 's') {
						printf("\nVetor depois da ordenação: ");
						printVetor(vetor, tamVetor);
					}
					
					printf("Comparações: %lu\n", numComp);
					printf("Tempo de execução: %fs\n", tempoTotal);
				} else if (selectOrd == 2) {
					printf("\n1: Vetor em ordem crescente\n");
					printf("2: Vetor em ordem decrescente\n");
					printf("3: Vetor em ordem \"aleatória\"\n");
					scanf("%1hd", &selectCaso);
					getchar();

					if (selectCaso == 1)
						preencheVetorCresc(vetor, tamVetor);
					else if (selectCaso == 2)
						preencheVetorDecresc(vetor, tamVetor);
					else
						preencheVetorAleat(vetor, tamVetor);

					if (imprimeVetor == 'S' || imprimeVetor == 's') {
						printf("\nVetor antes da ordenação: ");
						printVetor(vetor, tamVetor);
					}
					
					comeco = clock();
					numComp = insertionSort(vetor, tamVetor);
					fim = clock();
					tempoTotal = ((double)fim - comeco) / CLOCKS_PER_SEC;

					if (imprimeVetor == 'S' || imprimeVetor == 's') {
						printf("\nVetor depois da ordenação: ");
						printVetor(vetor, tamVetor);
					}
					
					printf("Comparações: %lu\n", numComp);
					printf("Tempo de execução: %fs\n", tempoTotal);
				} else if (selectOrd == 3) {
					printf("\n1: Vetor em ordem crescente\n");
					printf("2: Vetor em ordem decrescente\n");
					printf("3: Vetor em ordem \"aleatória\"\n");
					scanf("%1hd", &selectCaso);
					getchar();

					if (selectCaso == 1)
						preencheVetorCresc(vetor, tamVetor);
					else if (selectCaso == 2)
						preencheVetorDecresc(vetor, tamVetor);
					else
						preencheVetorAleat(vetor, tamVetor);

					if (imprimeVetor == 'S' || imprimeVetor == 's') {
						printf("\nVetor antes da ordenação: ");
						printVetor(vetor, tamVetor);
					}
					
					comeco = clock();
					numComp = selectionSortRec(vetor, tamVetor);
					fim = clock();
					tempoTotal = ((double)fim - comeco) / CLOCKS_PER_SEC;

					if (imprimeVetor == 'S' || imprimeVetor == 's') {
						printf("\nVetor depois da ordenação: ");
						printVetor(vetor, tamVetor);
					}
					
					printf("Comparações: %lu\n", numComp);
					printf("Tempo de execução: %fs\n", tempoTotal);
				} else if (selectOrd == 4) {
					printf("\n1: Vetor em ordem crescente\n");
					printf("2: Vetor em ordem decrescente\n");
					printf("3: Vetor em ordem \"aleatória\"\n");
					scanf("%1hd", &selectCaso);
					getchar();

					if (selectCaso == 1)
						preencheVetorCresc(vetor, tamVetor);
					else if (selectCaso == 2)
						preencheVetorDecresc(vetor, tamVetor);
					else
						preencheVetorAleat(vetor, tamVetor);

					if (imprimeVetor == 'S' || imprimeVetor == 's') {
						printf("\nVetor antes da ordenação: ");
						printVetor(vetor, tamVetor);
					}
					
					comeco = clock();
					numComp = selectionSort(vetor, tamVetor);
					fim = clock();
					tempoTotal = ((double)fim - comeco) / CLOCKS_PER_SEC;

					if (imprimeVetor == 'S' || imprimeVetor == 's') {
						printf("\nVetor depois da ordenação: ");
						printVetor(vetor, tamVetor);
					}
					
					printf("Comparações: %lu\n", numComp);
					printf("Tempo de execução: %fs\n", tempoTotal);
				} else if (selectOrd == 5) {
					printf("\n1: Vetor em ordem crescente\n");
					printf("2: Vetor em ordem decrescente\n");
					printf("3: Vetor em ordem \"aleatória\"\n");
					scanf("%1hd", &selectCaso);
					getchar();

					if (selectCaso == 1)
						preencheVetorCresc(vetor, tamVetor);
					else if (selectCaso == 2)
						preencheVetorDecresc(vetor, tamVetor);
					else
						preencheVetorAleat(vetor, tamVetor);

					if (imprimeVetor == 'S' || imprimeVetor == 's') {
						printf("\nVetor antes da ordenação: ");
						printVetor(vetor, tamVetor);
					}
					
					comeco = clock();
					numComp = mergeSort(vetor, tamVetor);
					fim = clock();
					tempoTotal = ((double)fim - comeco) / CLOCKS_PER_SEC;

					if (imprimeVetor == 'S' || imprimeVetor == 's') {
						printf("\nVetor depois da ordenação: ");
						printVetor(vetor, tamVetor);
					}
					
					printf("Comparações: %lu\n", numComp);
					printf("Tempo de execução: %fs\n", tempoTotal);
				} else if (selectOrd == 6) {
					free(vetor);
					vetor = NULL;
					
					break;
				} else {
					fprintf(stderr, "[-] main(): opção inválida\n");
				}

				free(vetor);
				vetor = NULL;
				printf("\nPressione qualquer tecla para continuar");
				getchar();

				break;
			} while (1);
		} else if (select == 3) {
			break;
		} else {
			fprintf(stderr, "[-] main(): opção inválida\n");
		}
	} while (1);

	return 0;
}
