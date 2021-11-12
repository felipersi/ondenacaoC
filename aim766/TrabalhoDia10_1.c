/*
O trabalho consiste no desenvolvimento de um programa em C que leia “N” valores e armazene em memória. O programa deverá ter a possibilidade de ordenar números, caracteres (strings) e datas. 
O grupo deverá escolher no mínimo 3 (três) métodos de ordenação para implementar no programa. 
Dessa forma, o programa deverá ter a opção de leitura dos dados (manual e automática –através da leitura de arquivo ou geração randômica) e após a opção de ordenar dados usando os 3 (três) métodos de ordenação escolhidos pelo grupo. 
Para cada um dos métodos utilizados, o programa deverá apresentar os dados inseridos, os dados ordenados, informar quantas comparações (movimentações) foram necessárias para realizar a ordenação, bem como o tempo necessário para ordenar os dados (tempo para cada um dos métodos de ordenação). 
Ao usuário selecionar a opção de ordenar dados, o programa sempre irá apresentar o resultado da ordenação dos três métodos.
O programa deverá ter a opção de ordenar valores numéricos inteiros, reais, datas (em formato DD/MM/AAAA) e caracteres, como nomes e palavras.

- O grupo deverá desenvolver uma opção para inserção de vários valores, sem precisar inserir manualmente. Esta técnica pode ser através da leitura de um arquivo texto ou por meio de geração randômica. Mesmo com este recurso, o programa também deverá permitir a inserção manual de valores.
- O grupo deverá escolher e implementar (em C) 3 (três) métodos de ordenação estudados em aula.
- O grupo deverá utilizar funções recursivas para a implementação do programa.
- O grupo deverá considerar a característica do algoritmo a ser utilizado antes da implementação.
- O grupo poderá melhorar o programa, incluindo novas funcionalidades, desde que tenha como demonstrar a utilização do algoritmo de ordenação utilizado.
- Podem ser utilizadas diversas estruturas de dados, além de vetores (árvores, por exemplo).
- O programa deverá possuir uma função de contagem do tempo de execução de cada algoritmo, para análise entre as opções de ordenação. Essa função servirá para apresentar o tempo necessário para a execução de algoritmo.
- Na apresentação (em aula ou ao vivo no blackboard) ao professor, o grupo deverá ter clareza no funcionamento do algoritmo de ordenação utilizado. O professor poderá realizar perguntar específicas sobre o funcionamento do algoritmo utilizado.
- O grupo deverá apresentar a execução do programa com grande volume de dados, através da importação de arquivo ou geração de dados aleatórios. O número mínimo de dados a serem inseridos para esta ordenação é de 100 valores (na inserção via arquivo ou randômica), podendo ser um valor maior. O programa deverá ter a opção de inserção de valores manualmente. Neste caso, não há necessidade de inserção mínima de 100 valores.
- O grupo deverá apresentar a execução da ordenação com grande volume de valores numéricos e com a inserção manual.
Forma de entrega e avaliação: O trabalho deverá ser apresentado e entregue (rodando) em sala de aula (ou ao vivo no blackboard), 
ao professor, no dia estipulado no cronograma. Após a apresentação, cada aluno deverá postar individualmente o trabalho no blackboard. 
O integrante do grupo que não postar o trabalho completo do seu grupo no prazo determinado ficará sem nota nesta avalição.

*/




//Busca Sequencial Linear - Ira percorrer posicao por posicao do vetor ate encontrar/ou nao encontrar o valor solicitado
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamanho 50

//FUNCOES
void ReadVector(int sizeVet); //funcao para ler o vetor e definir o seu tamanho
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
    int option_method;

 int numeros[tamanho] = {0};
    int i, r, aux;


    printf ("\n1 - Busca Linear Sequencial Numerica\n2 - Busca Binario Numerica\n ");
    scanf("%d",&option_method);
    
    if (option_method==1){
            int option_action;        
            switch(option_method)
            {
            case 1:
                printf("\nLista numerica gerada: \n");
                ReadVector(tamanho);
                printf ("\n\n1 - Buscar Numero | 2 - Ordenar Numeros\n ");
                scanf("%d",&option_action);
            break;    
            default:
            printf("\nOpcao invalida");
            break;
            }
        }
      /*else if (option_method == 2) {
    
    int option_action;

    if(option_action==1){
    
        printf ("\n1 - Buscar Palavra | 2 - Ordenar Palavras\n ");
        scanf("%d",&option_action);

        switch(option_action)
        {
        case 1:
            printf("\n Elemento 1");
        break;    
        default:
          printf("\nOpcao invalida");
          break;
        }
    }*/



    srand(time(NULL));
    
    //lista ordenada:
    //todo: implementar ordenação do array e após a busca de forma linear
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
void ReadVector(int sizeVet)
{
    int i;
    int random_numbers;
    int numeros[tamanho] = {0};

    for( i = 0; i < sizeVet; i++)
    {/*'r' é uma variável randomica*/
        random_numbers = (rand( ) % 100) + 1;
        numeros[i] = random_numbers;
        printf("%d ", numeros[i]);
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