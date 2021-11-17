/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanho 100

void LeVetor(int vet[]);
void ImprimeVetor(int vet[]);
int PesquisaSequencial(int v[], int pesq);
int OrdenaSequencia(int v[]);

int main(int argc, char *argv[])
{
    int r, z;
    int point[tamanho] = {0};
    int pos, procura;
    int *vet = point;
    int i;
   
    vet = (int *)malloc(tamanho * sizeof(int));
    
    if(vet==NULL){
        printf("sem espaço em memória");
        system("pause");
        exit(1);
    }

    printf(" Gerando vetor: \n");
    for(i = 0; i < tamanho; i++){
        vet[i] = rand() % 100 + 1; 
        printf(" %3d ", vet[i]);
          if (i == 9 || i == 19 || i == 29 || i == 39 || i == 49 || i == 59 || i == 69 || i == 79 || i == 89) {
             putchar('\n');
            }    
        }

    //LeVetor(vet);

    printf ("\nDigite um valor para pesquisar: ");
    scanf("%d",&procura);
    printf("\n");
    //Imprime o vetor na tela
    //ImprimeVetor(vet);
    clock_t start_t, end_t, total_t;
    start_t = clock();

    pos=PesquisaSequencial(vet,procura);

    end_t = clock() - start_t;
    double time_taken = ((double)start_t)/CLOCKS_PER_SEC; // in seconds
    printf("\n\nTempo de execução MS: %f", time_taken);
    
    if (pos==-1)
    {
        putchar('\n');
        printf("\n\nValor nao encontrado no vetor!");
        putchar('\n');
    }
    else
    {
        putchar('\n');
        printf("\n\nValor encontrado na posicao: %d", pos+1);    
        putchar('\n');
    }

    OrdenaSequencia(vet);

    printf("\n\n");  
    system("PAUSE>>NULL");	
    
    free(vet);
return 0;


}

/*-----------------------------------
Efetua a leitura do vetor 
-------------------------------------*/
void LeVetor(int vet[])
{
      int i;
      for (i=0;i<tamanho;i++)
      {
          printf("Informe o valor %d: ", i+1);
          fflush(stdin);
          scanf("%d", &vet[i]);
      }
}

/*---------------------------------
Imprime o vetor na tela
-----------------------------------*/
void ImprimeVetor(int vet[])
{
      int i;
      for (i=0;i<tamanho;i++)
      {
          printf(" %d ", vet[i]);
      }
    printf(" \n");  
}

/*---------------------------------------------------
Busca sequencial
-----------------------------------------------------*/
int PesquisaSequencial(int v[], int pesq)
{
    int i;
    
     for(i=0;i<tamanho;i++)
     {
          printf("\nComparado com: %d", v[i]);
          if(v[i]==pesq)
          {
              return i;
          }
        
     }
   
    return -1;   // não encontrado
}

/*---------------------------------------------------
Ordena sequencia
-----------------------------------------------------*/
int OrdenaSequencia(int v[])
{
    int aux;
    int i, r;
    clock_t start_t, end_t, total_t;
    putchar('\n');
    printf("\nValores Ordenados:\n\n");
    
    for(i = 0; i < tamanho; i++){
          for(r = i; r < tamanho; r++){
                if (v[i] > v[r]){
                   aux = v[r];
                   v[r] = v[i];
                   v[i] = aux;
                }
          }
          printf("%3d ", v[i]);
          if (i == 9 || i == 19 || i == 29 || i == 39 || i == 49 || i == 59 || i == 69 || i == 79 || i == 89) {
             putchar('\n');
            }
        }
    return i;
}
