//Busca Sequencial Linear - Ira percorrer posicao por posicao do vetor ate encontrar/ou nao encontrar o valor solicitado
#include <stdio.h>
#include <stdlib.h>


//FUNCOES
void ReadVector(int vet[],int sizeVet); //funcao para ler o vetor e definir o seu tamanho
void PrintVector(int vet[], int sizeVet); //funcao para mostrar o vetor
int SequentialSearch(int v[], int src, int sizeVet); //funcao para comparar os valores ate encontrar o valor solicitado pelo usuario

//MAIN
int main(int argc, char *argv[])
{
    int sizeVet;
   
    printf("Informe tamanho do vetor:  "); // solicitando tamanho do vetor
    scanf("%d", &sizeVet); // armazenando o tamanho do vetor na variavel sizeVet
   
    int vet[sizeVet];
    int pos, search;
    // lendo o vetor
    ReadVector(vet, sizeVet);
        
    printf ("\nDigite um valor para pesquisa: ");
    scanf("%d",&search);
    
    //Imprime o vetor na tela
    PrintVector(vet, sizeVet);
    
    pos=SequentialSearch(vet,search, sizeVet); // mostra a msg conforme o resultado da busca sequencial -- linha 75
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
Efetua a leitura do vetor e solicita o preenchimento ao usuario
-------------------------------------*/
void ReadVector(int vet[], int sizeVet)
{
      int i;
      for (i=0;i<sizeVet;i++)
      {
          printf("Informe o valor %d: ", i);
          fflush(stdin); // limpar o buffer do teclado
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
Busca sequencial - percorre cada posicao do vetor ate encontrar o valor desejado(se for encontrada para imediatamente e mostra em qual posicao foi encontrado)
(se nao for encontrado retorna msg de que nao foi encontrado o valor dentro do vetor)
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