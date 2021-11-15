/*

*/
#include <stdio.h>
#include <stdlib.h>

#define tamanho 50

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

    //Lê a vetor
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
          if (i == 9 || i == 19 || i == 29 || i == 39 || i == 49){
             putchar('\n');
            }    
        }

    //LeVetor(vet);

    printf ("\nDigite um valor para pesquisar: ");
    scanf("%d",&procura);
    printf("\n");
    //Imprime o vetor na tela
    //ImprimeVetor(vet);

    pos=PesquisaSequencial(vet,procura);
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
          if (i == 9 || i == 19 || i == 29 || i == 39 || i == 49){
             putchar('\n');
            }
        }
    return i;
}
