#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#define TAM 500000
#define MAX 101

void exibeVetor (int vet[TAM]){
    int i;
    printf("\n|");
    for (i=0;i<TAM; i++){
        printf (" %d |", vet[i]);
    }
    printf("\n");
}
void criarVetor (int vet[TAM]){
    int i;
    srand(time(NULL));
    for (i=0;i<TAM;i++){
        vet[i]=rand()%MAX;
    }
    // exibeVetor(vet);
}
void metodoSelecao (int vet[TAM]){
    int menor, aux;
    for (int i = 0; i<TAM; i++){//for para navegar em todas as posições 
        menor = i;
        for (int j = i+1; j < TAM; j++){
            if (vet[menor]>vet[j])
            menor = j;
        }
        if (i!=menor){
            aux = vet[i];//o auxiliar recebe o que tá na posicao
            vet[i] = vet[menor];//o vetor vai receber o menor valor encontrado
            vet[menor] =aux;//a posição onde esse menor valor estava antes vai receber o auxiliar
        }
    }
}
void metodoInsercaoDireta (int vet[TAM]){
    int aux, pos;

    for (int i = 1; i < TAM; i++){//loop externo que percorre o vetor
         aux = vet[i];//variavel auxiliar copia elemento da posição i
         pos = i; //armazena posição
         while (pos > 0 && vet[pos-1]>aux){ //o while testa se a posição é maior q 0 e a posição anterior a atual do vetor é maior que a auxiliar
            vet[pos] = vet[pos-1];//caso seja, a posição atual irá armazenar o valor a posição anterior
            pos--;//posição drecresce para while ir testando e reposionando 
         }
         vet[pos] = aux;//quando sair do loop while o vetor da posição recebe o auxiliar
    }
}
void metodoInsercaoBinaria (int vet[TAM], int num) {
    int tam = TAM;
    int esquerda = 0, direita = tam - 1;
    int meio, posicao;

    while (esquerda <= direita) {
        meio = (esquerda + direita) / 2;

        if (vet[meio] == num) {
            posicao = meio;
            break;
        } else if (num < vet[meio]) {
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }

    if (esquerda > direita) {
        posicao = esquerda;
    }

    for (int i = tam - 1; i >= posicao; i--) {
        vet[i + 1] = vet[i];
    }

    vet[posicao] = num;
}

void metodoBolha (int vet[TAM]){
    int aux;
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM-i-1; j++){
            if (vet[j] > vet [j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }

}
void metodoQuickSort (int vet[], int inicio, int fim) {
    int aux, i, j, pivo;
    i = inicio; j = fim;
    pivo = vet[(i + j) / 2];
    do {
        while (vet[i] < pivo) i++;
        while (vet[j] > pivo) j--;
        if (i <= j) {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > inicio) metodoQuickSort(vet, inicio, j);
    if (i < fim) metodoQuickSort(vet, i, fim);
}

void startaQuick(int vet [], int tam) {
    metodoQuickSort (vet, 0, tam - 1);
}

void metodoHeapSort (int vet[TAM]){
    int tam = TAM;
   int i = tam / 2, pai, filho, t;
    while (true) {
        if (i > 0) {
            i--;
            t = vet[i];
        } else {
            tam--;
            if (tam <= 0) return;
            t = vet[tam];
            vet[tam] = vet[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < tam) {
            if ((filho + 1 < tam) && (vet[filho + 1] > vet[filho]))
                filho++;
            if (vet[filho] > t) {
                vet[pai] = vet[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } else {
                break;
            }
        }
        vet[pai] = t;
    }
}
void metodoShellSort (int vet[TAM]){
int intervalo, i, j, aux;
    for (intervalo = TAM/2; intervalo > 0; intervalo /= 2) {
        for (i = intervalo; i < TAM; i++) {
        aux = vet[i];
        for (j = i; j >= intervalo && vet[j-intervalo] > aux; 
        j -= intervalo) {
        vet[j] = vet[j-intervalo];
}
        vet[j] = aux;
    }
    }
}     
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

int metodoBuscaSequencial (int vet[TAM]){
    int num, pos, i=0; 
    printf ("\nEntre com o numero que deseja buscar: ");
    scanf ("%d", &num); 
     for (int i = 0; i < TAM && vet[i] <= num; i++) {
        if (vet[i] == num) {
            return i;
        }
    }
    return -1;
}  
void metodoBuscaExaustiva (int vet[TAM]){
    int num, pos;
    printf ("\nEntre com o numero que deseja buscar: ");
    scanf ("%d", &num); 
    for (int i = 0; i < TAM; i++){
        if (vet[i] == num){
            printf ("\nEncontrado na posicao: %d", i); 
        }
    }
}
int metodoBuscaBinaria (int vet[TAM]){
    int num, inicio = 0, meio, fim = TAM-1; 
    meio = (inicio+fim)/2;   
    printf ("\nEntre com um numero: "); 
    scanf ("%d", &num); 
    while (inicio <= fim) {//condição de parada
        meio = (inicio + fim) / 2;//calcula o meio
        if (vet[meio] == num) {
            return meio; // elemento encontrado
        } else if (vet[meio] < num) {
            inicio = meio + 1; // descarta a metade esquerda do vetor
        } else {
            fim = meio - 1; // descarta a metade direita do vetor
        }//| 4 | 23 | 48 | 49 | 54 | 57 | 68 | 68 | 70 | 86 | 86 | 93 | 96 | 99 | 100 |
    }
    return -1; // elemento não encontrado
}
int metodoBuscaBinariaRecursiva (int vet[], int num, int inicio, int fim) {
    int meio;
    if (inicio > fim)
        return -1; 
    else {
        meio = (inicio+fim) / 2;
        if (num == vet[meio])
            return meio;
        else if (num < vet[meio])
            metodoBuscaBinariaRecursiva(vet,num,inicio ,meio-1);
        else
            metodoBuscaBinariaRecursiva(vet,num,meio+1,fim);
    }
}


int main (){
setlocale(LC_ALL, "Portuguese");
int op, vet[TAM], aux, num; 
clock_t tempoi, tempof;
time_t ti, tf; 
float difTempo;
bool ordenado = false;
double milissegundos;
while (op!=15){
printf ("\n\nEscolha uma das opcoes:\n");
printf ("\nCriacao e exibicao de vetor de %d elementos: ", TAM);
printf ("\n1 - Criar e preencher vetor randomicamente");//feito
printf ("\n2 - Exibir vetor");//feito
printf ("\n__________________________________");
printf ("\nMetodos de ordenacao: ");
printf ("\n3 - Ordenar por meio do metodo SELECAO");//feito
printf ("\n4 - Ordenar por meio do metodo INSERCAO DIRETA");//feito
printf ("\n5 - Ordenar por meio do metodo INSERCAO BINARIA");
printf ("\n6 - Ordenar por meio do metodo BOLHA");//feito
printf ("\n7 - Ordenar por meio do metodo QUICKSORT");
printf ("\n8 - Ordenar por meio do metodo HEAPSORT");//feito
printf ("\n9 - Ordenar por meio do metodo SHELLSORT");//feito
printf ("\n10 - Ordenar por meio do metodo MERGESORT");//feito
printf ("\n__________________________________");
printf ("\nMetodos de busca: ");
printf ("\n11 - Buscar por meio do metodo de busca SEQUENCIAL");//feito
printf ("\n12 - Buscar por meio do metodo de busca EXAUSTIVA"); //feito
printf ("\n13 - Buscar por meio do metodo de busca BINARIA");//feito
printf ("\n14 - Buscar por meio do metodo de busca BINARIA (com uso de recursividade)");//feito
printf ("\n__________________________________");
printf ("\n\n15 - Sair");
printf ("\nQual a sua opcao? ");
scanf ("%d", &op);
system("cls"); 

switch (op){

    case 1: criarVetor (vet);
    break;

    case 2: exibeVetor (vet);
    break;

    case 3: tempoi = clock(); //tempo inicial para cronometrar
    metodoSelecao(vet);
    tempof = clock();
    difTempo = (double)(tempof - tempoi) / CLOCKS_PER_SEC;
    printf("\nOrdenou vetor e demorou %.3f segundos num vetor de %d elementos", difTempo, TAM);
	ordenado=true;
    break;

    case 4:  tempoi = clock();  
    metodoInsercaoDireta(vet);
    tempof = clock();
    difTempo = (double)(tempof - tempoi) / CLOCKS_PER_SEC;
    printf("\nOrdenou vetor e demorou %.3f segundos num vetor de %d elementos", difTempo, TAM);
	ordenado=true;
    break;

    case 5: ti = time (NULL);
    printf ("\nEntre com o numero que deseja buscar: ");
    scanf ("%d", &num); //preciso abrir espaço no vetor, mas tamanho está definido como uma constante, utilizar alocação dinamica. 
    metodoInsercaoBinaria(vet, num);
    tf = time (NULL); 
    difTempo = difftime (tf, ti); 
    printf ("\nOrdenou vetor e demorou %.3f segundos num vetor de %d elementos", difTempo, TAM); 
    break;

    case 6: tempoi = clock(); //tempo inicial para cronometrar
    metodoBolha(vet);
    tempof = clock();
    difTempo = (double)(tempof - tempoi) / CLOCKS_PER_SEC;
    printf("\nOrdenou vetor e demorou %.3f segundos num vetor de %d elementos", difTempo, TAM);
    ordenado = true; 
    break;

    case 7: tempoi = clock();
    startaQuick(vet, TAM);
    tempof = clock();
    difTempo = (double) (tempof- tempoi) / CLOCKS_PER_SEC;
    milissegundos = difTempo * 1000.0;
    printf("\nOrdenou vetor e demorou %.3f milissegundos em um vetor de %d elementos", milissegundos, TAM); 
    ordenado = true;
    break;

    case 8: tempoi = clock();
    metodoHeapSort(vet);
    tempof = clock();
    difTempo = (double) (tempof- tempoi) / CLOCKS_PER_SEC;
    milissegundos = difTempo * 1000.0;
    printf("\nOrdenou vetor e demorou %.3f milissegundos em um vetor de %d elementos", milissegundos, TAM);  
    ordenado = true;
    break;

    case 9: tempoi = clock();
    metodoShellSort(vet);
    tempof = clock();
    difTempo = (double) (tempof- tempoi) / CLOCKS_PER_SEC;
    milissegundos = difTempo * 1000.0;
    printf("\nOrdenou vetor e demorou %.3f milissegundos em um vetor de %d elementos", milissegundos, TAM); 
    ordenado = true;
    break;

    case 10: tempoi = clock();
    metodoMergeSort(vet, 0, TAM-1); 
    tempof = clock();
    difTempo = (double) (tempof- tempoi) / CLOCKS_PER_SEC;
    milissegundos = difTempo * 1000.0;
    printf("\nOrdenou vetor e demorou %.3f milissegundos em um vetor de %d elementos", milissegundos, TAM); 
    ordenado = true;
    break;

    case 11: if (ordenado)
    {
        aux = metodoBuscaSequencial (vet);
        if (aux == -1) {
         printf ("\nNao achou");
        }
        else{
         printf ("\nAchou na posicao %d", aux);
        }
    }  
    else
    printf ("\nOrdene vetor antes"); 
    break;
    
    case 12:  metodoBuscaExaustiva (vet);
    break;

    case 13: if (ordenado) {
    aux = metodoBuscaBinaria (vet);
    if (aux == -1){
        printf ("\nNao achou");
    }
    else {
        printf ("\nAchou na posicao %d", aux); 
    }
    }
    else
    printf ("\nOrdene o vetor antes"); 
    break;
    case 14: if (ordenado) {
    printf ("\nEntre com o numero que deseja buscar: ");
    scanf ("%d", &num);
    aux = metodoBuscaBinariaRecursiva (vet, num, 0, TAM-1);
    if (aux == -1){
        printf ("\nNao achou");
    }
    else {
        printf ("\nAchou na posicao %d", aux); 
    }
    }
    else
    printf ("\nOrdene o vetor antes"); 
    break;

}
}

    return 0;
}



 