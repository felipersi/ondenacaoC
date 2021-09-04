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
#include <conio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include<time.h>//necessário p/ função time()


int main()
{
    int numlist;
    int i;
    int vetOriginal[i], vetInvert[i];

    printf("Quantos numeros deseja gerar na lista: ");
    scanf("%d", &numlist);  
    printf("numero = %d \n\n",numlist);
    
    srand(time(NULL));
    
        if (numlist >= 1) {
            printf(" Valor Original: \n");
             for(i = 0; i < numlist; i++) {
                vetOriginal[i] = rand() % 100;
                printf(" %d ", vetOriginal[i]);
            }
            printf("\n Valor Invertido: \n");
            for(i = 0; i < numlist; i++) {
                vetInvert[i] = vetOriginal[numlist-i-1];
                printf(" %d ", vetInvert[i]);
            }
            return 0;
    
        } else {
            printf("Erro: sem condição valida");
        }


}