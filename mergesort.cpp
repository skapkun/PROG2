#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 50
void mesclar(int vet[], int inicio, int meio, int fim) {
    int tam = fim - inicio + 1;
    int *vet_aux = (int *) malloc(tam * sizeof(int));
    int i = inicio, j = meio + 1, k = 0;

    for (k = 0; k < tam; k++) {
        if (i > meio) {
            vet_aux[k] = vet[j++];
        } else if (j > fim) {
           vet_aux[k] = vet[i++];
        } else if (vet[i] < vet[j]) {
           vet_aux[k] = vet[i++];
        } else {
           vet_aux[k] = vet[j++];
        }
    }

    for (k = 0; k < tam; k++) {
        vet[inicio + k] = vet_aux[k];
    }

    free(vet_aux);
}

void metodoMergeSort(int vet[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        metodoMergeSort(vet, inicio, meio);
        metodoMergeSort(vet, meio + 1, fim);
        mesclar(vet, inicio, meio, fim);
    }
}

int MERGE(int vetorA[100], int tamA, int vetorB[100], int tamB, int vetorC[200]){
    int i = 0, j = 0, k = 0;
    // Percorre os vetores A e B, comparando os elementos e inserindo no vetor C
    while (i < tamA && j < tamB) {
        if (vetorA[i] <= vetorB[j]) {
            vetorC[k] = vetorA[i];
            i++;
        } else {
            vetorC[k] = vetorB[j];
            j++;
        }
        k++;
    }
    // Copia os elementos restantes do vetor A, se houver
    while (i < tamA && vetorA[i] != 999) {
        vetorC[k] = vetorA[i];
        i++;
        k++;
    }
    // Copia os elementos restantes do vetor B, se houver
    while (j < tamB && vetorB[j] != 999) {
        vetorC[k] = vetorB[j];
        j++;
        k++;
    }
    // Adiciona o elemento 999 no final do vetor C e retorna o tamanho lógico do vetor C
    vetorC[k] = 999;
    return k;
}

void exibeVetor (int vetor[], int tam){
for (int i = 0; i < tam; i++) { 
        printf("%d ", vetor[i]);
    }
}

int main() {

    int vetA[TAM] = {10, 30, 40, 60, 80, 90, 999};
    int tamanhoA = 7;
    int vetB[TAM] = {20, 50, 70, 70, 999};
    int tamanhoB = 5;
    int vetC[TAM], tamanhoC;
    int vetorA[TAM], vetorB[TAM], vetorC[100];
    int tamA, tamB, tamC;

    srand(time(NULL)); // inicializa a semente para gerar números aleatórios

    // gerando tamanhos aleatórios para os vetores A e B
    tamA = rand() % 20 + 1;
    tamB = rand() % 20 + 1;   
    
    // gerando valores aleatórios para os elementos dos vetores A e B
    printf("Vetor A gerado randomicamente: ");
    for (int i = 0; i < tamA; i++) {
        vetorA[i] = rand() % 1000 + 1;
    }
    exibeVetor (vetorA, tamA);
    printf("\n");

    printf("Vetor B gerado randomicamente: ");
    for (int i = 0; i < tamB; i++) {
        vetorB[i] = rand() % 1000 + 1; 
    }
    exibeVetor (vetorB, tamB);
    printf("\n\n");
     metodoMergeSort(vetorA, 0, tamA);
    metodoMergeSort(vetorB, 0, tamB);

    printf("Vetor A ordenado pelo metodo MERGESORT: ");
    exibeVetor (vetorA, tamA);
    printf("\n");

    printf("Vetor B ordenado pelo metodo MERGESORT: ");
    exibeVetor (vetorB, tamB);
    printf("\n\n");
    // chamando a função MERGE para unir os vetores A e B em C
    tamC = MERGE(vetorA, tamA, vetorB, tamB, vetorC);

    // imprimindo o vetor C ordenado
    printf("Vetor C gerado pela mesclagem dos vetores A e B: ");
    exibeVetor (vetorC, tamC);
    printf("\n\n");

    printf("Vetor A no exemplo dado: ");
    exibeVetor(vetA, tamanhoA);
    printf("\n");
    printf("Vetor B no exemplo dado: ");
    exibeVetor(vetB, tamanhoB);
    printf("\n");
    tamanhoC = MERGE (vetA, tamanhoA, vetB, tamanhoB, vetC); 
    printf("Vetor C no exemplo dado: ");
    exibeVetor(vetC, tamanhoC);
    return 0;
}
