//Busca Sequencial Linear - Ira percorrer posicao por posicao do vetor ate encontrar/ou nao encontrar o valor solicitado
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamanho 50

//FUNCOES
void ReadVector(int vet[],int sizeVet); //funcao para ler o vetor e definir o seu tamanho
void PrintVector(int vet[], int sizeVet); //funcao para mostrar o vetor
int SequentialSearch(int v[], int src, int sizeVet); //funcao para comparar os valores ate encontrar o valor solicitado pelo usuario

//MAIN
int main(int argc, char *argv[])
{
    int sizeVet;
    int option;
    int type;
    int cont;
    int min, max;

 int numeros[tamanho] = {0};
    int i, r, aux;


    printf ("\n1 - Busca Linear Sequencial \n2 - Busca Binario\n ");
    scanf("%d",&option);
    
    printf ("\n1 - Numérico\n2 - A-Z\n ");
    scanf("%d",&type);

    srand(time(NULL));
    
    for( i = 0; i < tamanho; i++)
    {/*'r' é uma variável randomica*/
        r = (rand( ) % 100) + 1;
        numeros[i] = r;
        printf("%d .", numeros[i]);
    }
    
    printf("\t50 Numeros Aleatorios devidamente ordenados de forma crescente:");
    putchar('\n');
    
    /* 'r' passará a ser contador*/
    for(i = 0; i < tamanho; i++){
          for(r = i; r < tamanho; r++){
                if (numeros[i] > numeros[r]){
                   aux = numeros[r];
                   numeros[r] = numeros[i];
                   numeros[i] = aux;
                }
          }
          
          printf("%3d ", numeros[i]);
          /* O 'if' abaixo apresenta como única função organizar em um formato semelhante a uma tabela
             os numeros randomicos gerados, devidamente ordenados*/
          if (i == 9 || i == 19 || i == 29 || i == 39 || i == 49){
             putchar('\n');
            }
    }

    exit(0);
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