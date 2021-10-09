#include <stdio.h>
#include <stdlib.h>


/*#define tamanho 5*/

void ReadVector(int vet[],int tamanho);
void PrintVector(int vet[], int tamanho);
int SequentialSearch(int v[], int pesq, int tamanho);

int main(int argc, char *argv[])
{
    int tamanho;
   
    printf("Informe tamanho do vetor  ");
    scanf("%d", &tamanho);
   
    int vet[tamanho];
    int pos, procura;
    //Lê a vetor
    ReadVector(vet, tamanho);
        
    printf ("\nDigite um valor para pesquisar: ");
    scanf("%d",&procura);
    
    //Imprime o vetor na tela
    PrintVector(vet, tamanho);
    
    pos=SequentialSearch(vet,procura, tamanho);
    if (pos==-1)
    {
        printf("\n\nValor nao encontrado no vetor!");
    }
    else
    {
        printf("\n\nValor encontrado na posicao %d", pos+1);    
    }
       
    printf("\n\n");  
    system("PAUSE>>NULL");	
    return 0;
}

/*-----------------------------------
Efetua a leitura do vetor 
-------------------------------------*/
void ReadVector(int vet[], int tamanho)
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
void PrintVector(int vet[], int tamanho)
{
      int i;
      for (i=0;i<tamanho;i++)
      {
          printf("%d", vet[i]);
      }
}

/*---------------------------------------------------
Busca sequencial
-----------------------------------------------------*/
int SequentialSearch(int v[], int pesq, int tamanho)
{
     int i;
     for(i=0;i<tamanho;i++)
     {
          if(v[i]==pesq)
          {
              return i;
          }
     }
     return -1;   // não encontrado
}