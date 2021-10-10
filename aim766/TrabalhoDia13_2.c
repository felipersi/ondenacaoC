//Busca Sequencial Linear
#include <stdio.h>
#include <stdlib.h>

void ReadVector(int vet[],int sizeVet);
void PrintVector(int vet[], int sizeVet);
int SequentialSearch(int v[], int src, int sizeVet);

int main(int argc, char *argv[])
{
    int sizeVet;
   
    printf("Informe tamanho do vetor:  ");
    scanf("%d", &sizeVet);
   
    int vet[sizeVet];
    int pos, search;
    //Lê a vetor
    ReadVector(vet, sizeVet);
        
    printf ("\nDigite um valor para pesquisa: ");
    scanf("%d",&search);
    
    //Imprime o vetor na tela
    PrintVector(vet, sizeVet);
    
    pos=SequentialSearch(vet,search, sizeVet);
    if (pos==-1)
    {
        printf("\n\nValor nao encontrado no vetor!");
    }
    else
    {
        printf("\n\nValor encontrado na posicao %d", pos);    
    }
       
    printf("\n\n");  
    system("PAUSE>>NULL");	
    return 0;
}

/*-----------------------------------
Efetua a leitura do vetor 
-------------------------------------*/
void ReadVector(int vet[], int sizeVet)
{
      int i;
      for (i=0;i<sizeVet;i++)
      {
          printf("Informe o valor %d: ", i);
          fflush(stdin);
          scanf("%d", &vet[i]);
      }
}

/*---------------------------------
Imprime o vetor na tela
-----------------------------------*/
void PrintVector(int vet[], int sizeVet)
{
      int i;
      for (i=0;i<sizeVet;i++)
      {
          printf(" %d", vet[i]);
      }
}

/*---------------------------------------------------
Busca sequencial
-----------------------------------------------------*/
int SequentialSearch(int v[], int src, int sizeVet)
{
     int i;
     for(i=0;i<sizeVet;i++)
     {
         printf("\n");
         printf("Comparado com: %d", v[i]);
          if(v[i]==src)
          {
              return i;
          }
     }
     return -1;   // não encontrado
}