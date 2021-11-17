/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanho 100 //tamanho minimo do array numérico

void LeVetor(int vet[]); //função de leitura do vetor
void ImprimeVetor(int vet[]);//função que printa o vetor
int PesquisaSequencial(int v[], int pesq); //função que faz a pesquisa por um valor dentro do vetor
int OrdenaSequencia(int v[]); //função que ordena o vetor

int main(int argc, char *argv[])
{
    int r, z;
    int point[tamanho] = {0};
    int pos, procura;
    int *vet = point; // iniciando o ponteiro
    int i;
   
    vet = (int *)malloc(tamanho * sizeof(int)); //alocação dinamica de valores em memória através do ponteiro
    
    if(vet==NULL){ //verifica se há memória o suficiente
        printf("sem espaço em memória");
        system("pause");
        exit(1);
    }

    printf(" Gerando vetor: \n"); //gera vetor numérico randomicamente
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
    start_t = clock(); //inicia contagem de tempo da busca de um dado de forma sequencia linear no vetor

    pos=PesquisaSequencial(vet,procura); //chamada da função de pesquisa

    end_t = clock() - start_t; //finaliza execução
    double time_taken = ((double)start_t)/CLOCKS_PER_SEC; 
    printf("\n\nTempo de execução MS: %f", time_taken); //imprime valor de quanto tempo levou a execução
    
    if (pos==-1) //verifica se digitado pelo usuario foi ou não encontrado
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

    OrdenaSequencia(vet); //onrdena o array

    printf("\n\n");  
    system("PAUSE>>NULL");	
    
    free(vet);//libera a memória
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
          fflush(stdin);// limpar o buffer do teclado
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
Busca sequencial - percorre cada posicao do vetor ate encontrar o valor desejado(se for encontrada para imediatamente e mostra em qual posicao foi encontrado)
(se nao for encontrado retorna msg de que nao foi encontrado o valor dentro do vetor)
------------------------------------------------------*/

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
    
    for(i = 0; i < tamanho; i++){ //ordenação dos valores de forma crescente
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
