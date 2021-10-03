
// C program for Indexed Sequential Search
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void indexedSequentialSearch(int arr[], int n, int k);

// Driver code
int main(){

    //printf("Elementos inseridos: 6, 7, 8, 9, 10, 11, 12 ,13 ,14, 15, 16, 17 \n");

    int arr[100];
    int k,i;
    int sizelist;
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(NULL));
    // Element to search
    printf("Digite o tamanho da lista até 50: ");
    scanf("%d", &sizelist);
        // GERA LISTA
        for(i = 0; i < sizelist; i++) {
            arr[i] = rand() % 100;
            printf(" %d ", arr[i]);
    }
    
    printf("\nTamanho do array inserido: %d\n",sizelist);
    printf("\n");
    
    printf("\n Digite o numero a ser localizado: ");
    scanf("%d",&k);

    //int k = 8;

    indexedSequentialSearch(arr, sizelist, k);
}


void indexedSequentialSearch(int arr[], int n, int k){

    int elements[50];
    int indices[50];
    int temp;
    int i;

    int j = 0;
    int ind = 0;
    int start;
    int end;
    //debug

    printf("array: %d | int n: %d | int k: %d", arr[i],n,k);
    //debug

    printf("\n Criando o a tabela de indices...\n ");
    for (i = 0; i < n; i++){
        printf(" - O indice[%d] recebeu  o valor %d\n",i,arr[i]);
        arr[i] = i;
    }
    //DEBUG
    //printf("\n");
    //printf("ELEMENTO 0: %d",elements[0]);
    //printf("\n\n");
    //Debug
    
    if (k < elements[0]){
        printf("Nao localizado11 %d \n", k);
        exit(0);
    }
    else {
        printf("\n\n");
        for (i = 1; i <= n; i++)
            if (k < elements[i]){
                start = indices[i - 1];
                printf("START: %d \n",start);
                end = 100;
                printf("END: %d \n",end);
                break;
            }

    }

    for (i = 0; i <= end; i++){
        if (k == arr[i]){
            j = 1;
            break;
        }
    }

    if (j == 1)
        printf("Localizado o elemento %d no indice %d", k,i);
    else
        printf("Nao localizado2: %d", k);
}




