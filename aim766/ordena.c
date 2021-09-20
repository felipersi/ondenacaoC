/******************************************************************************
O programa deverá:
- Criar um arquivo texto e gerar uma sequência aleatória de números separados por “;” (ponto e vírgula).
O usuário deverá inserir quantos números deseja gerar no arquivo (no mínimo 100 números).
- Após a geração do arquivo, o programa deverá ter uma função para carregar o arquivo. Ao carregar o arquivo, 
o programa deverá armazenar os valores em um array.
- O programa também deverá possuir as seguintes funcionalidades, após a execução das etapas anteriores:
-  opção para inversão dos elementos do arquivo (ou seja, o programa deverá ter uma função de gerar um novo arquivo 
com os elementos invertidos).
-  opção de geração de um novo arquivo com os elementos ordenados.
- opção de geração de um novo arquivo com o maior e o menor número encontrado no arquivo e a média de todos os 
números do arquivo.
- opção de geração de um novo arquivo em que cada número do arquivo original é convertido para binário.
Forma de entrega e avaliação: o trabalho deverá ser entregue e apresentado (código rodando) ao professor, em sala de aula, no dia definido no cronograma da disciplina. Após a apresentação, o aluno deverá postar o código-fonte (.c) na área de atividades do blackboard.
Nota: a avaliação será de 0-10. 0 para o trabalho não entregue e 10 para o trabalho que atenda totalmente aos critérios.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include<time.h>//necessário p/ função time()


int main()
{
    int numlist;
    int i, j;
    int vetOriginal[i], vetInvert[i];
    int max = 0;
    int min = 0;
    int c, k;
    int aux, operationNum;
    char fileName[50];
    char fileNameInvert[50];

    FILE *createFile;
    srand(time(NULL));
    
    printf("Quantos numeros deseja gerar na lista: ");
    scanf("%d", &numlist);  
    printf("numero = %d \n\n",numlist);
    printf("Digite o nome do arquivo: ");
    scanf("%s",fileName);
    
    createFile = fopen(fileName, "w");
  
    if (createFile==NULL && numlist >= 1) {
      printf("Falha ao criar o arquivo.");
      exit(1); 
  } 
    else {
      printf(" Valor Original: ");
        for(i = 0; i < numlist; i++) {
          vetOriginal[i] = rand() % 100;
          fprintf(createFile, "%d; ", vetOriginal[i]);
          printf(" %d ", vetOriginal[i]);
  }

}
do{
    printf("\n\n===Escolha umas das opções abaixo===");
    printf("\n1- Inverter Elementos.");
    printf("\n2- Gerar novo arquivo com elementos ordenados.");
    printf("\n3- Novo arquivo com maior e menor valor encontrado.");
    printf("\n4- Novo arquivo com numeros convertidos para binario.");
    printf("\n5- Sair.");
    printf("\nDigite uma opcao:  ");
    scanf("%d", &operationNum);
 
    switch(operationNum){
    case 1:
      printf("Digite o nome do arquivo invertido: ");
      scanf("%s",fileNameInvert);
      createFile = fopen(fileNameInvert, "w");
      for(i = 0; i < numlist; i++) {
          vetInvert[i] = vetOriginal[numlist-i-1];

          fprintf(createFile, "%d; ", vetInvert[i]);

          printf(" %d ", vetInvert[i]);
        }
    break;
    case 2: 
      printf("Digite o nome do arquivo: ");
      scanf("%s",fileName);
        for(i = 0; i < numlist; i++) {
          for( j=i+1; j<numlist; j++ ){
            if( vetOriginal[i]  > vetOriginal[j]  ){
                aux = vetOriginal[i];
                vetOriginal[i] = vetOriginal[j];
                vetOriginal[j] = aux;
                }
              }
            }
          printf("\n Valor Ordenado:");
            for(i=0;i<=numlist;i++){
              fprintf(createFile, "%d; ", vetOriginal[i]);
              printf(" %d ",vetOriginal[i]);
              }         
    break;
    case 3:
        printf("\n");
        printf("Digite o nome do arquivo: ");
        scanf("%s",fileName);
          for(i = 0; i < numlist; i++) {
              if (vetOriginal[i]>max)
                    max = vetOriginal[i];
                else
                    if (vetOriginal[i]<min)
                       min = vetOriginal[i];
            }
            fprintf(createFile, "%d; %d ", max,min);
            printf("\n Maior valor: %d", max);
            printf("\n Menor valor %d", min);
      break;
      case 4:
        printf("Digite o nome do arquivo: ");
        scanf("%s",fileName);
              for(i = 0; i < numlist; i++) {
              printf("\n %d em binario: ", vetOriginal[i]);
              for (c = 40; c >= numlist; c--)
              {
                k = vetOriginal[i] >> c;
                int o = 1;
                int z = 0;

                if (k & 1) {
                  fprintf(createFile, "%d; ", o);
                  printf("1");
                } else {
                  fprintf(createFile, "%d; ", z);
                  printf("0");
                }
              }
            }
      break;
    default:
      printf("opcao invalida! tente novamente...\n");
      system ("pause");
    }
  } while(operationNum !=5);

}