// C program for Indexed Sequential Search
#include <stdio.h>
#include <stdlib.h>

void indexedSequentialSearch(int arr[], int n, int k);

// Driver code
void main(){

    printf("Elementos inseridos: 6, 7, 8, 9, 10, 11, 12 ,13 ,14, 15, 16, 17 \n");

    int arr[] = { 6, 7, 8, 9, 10, 11, 12 ,13 ,14, 15, 16, 17  };
    int k;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Tamanho do array inserido: %d\n",n);
    
    // Element to search
    printf("Digite o numero a ser localizado: ");

    scanf("%d",&k);

    //int k = 8;

    indexedSequentialSearch(arr, n, k);
}


void indexedSequentialSearch(int arr[], int n, int k){

    int elements[20];
    int indices[20];
    int temp;
    int i;

    int j = 0;
    int ind = 0;
    int start;
    int end;

    printf("array: %d | int n: %d | int k: %d", arr[i],n,k);


    printf("Criando o a tabela de indices...\n ");
    for (i = 0; i < n; i += 3){

        // Storing element
        elements[ind] = arr[i];

        // Storing the index
        printf(" - O indice[%d] recebeu  o valor %d\n",ind,elements[ind]);
        indices[ind] = i;
        ind++;
    }

    if (k < elements[0]){
        printf("Nao localizado");
        exit(0);
    }
    else {
        for (i = 1; i <= ind; i++)
            if (k < elements[i]){
                start = indices[i - 1];
                end = indices[i];
                break;
            }
    }

    for (i = start; i <= end; i++){
        if (k == arr[i]){
            j = 1;
            break;
        }
    }

    if (j == 1)
        printf("Localizado o elemento %d no indice %d", k,i);
    else
        printf("Nao localizado");
}