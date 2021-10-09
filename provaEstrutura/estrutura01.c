#include <stdlib.h>
#include <stdio.h>

// Estrutura criada da matriz em struct para manipulacao utilizando TAD.
struct matriz{

  int linha;
  int coluna;
  float* valor;

};

// O que faz e para utilizar nesse contexto?
typedef struct matriz Matriz;  // declara matriz como um tipo

// Funcao de criacao de uma Matriz utilizando TAD.
// Observe a funcao e explique o funcionamento da criacao da matriz utilizando TAD? Comente cada linha explicando cada item.
Matriz* cria(int m, int n){ // È uma funÁ„o que recebe dois valores m = linhas e n = colunas para a criaÁ„o de uma matriz

  Matriz* mat = (Matriz*)malloc(sizeof(Matriz));  // criar uma vari·vel com nome mat e reserva o espaÁo de memÛria para ela calculando o tamanho dela com a funcionalidade sizeof

  if (mat == NULL){ // verificar se foi possivel reservar o espaÁo de memÛria para a matriz, se retornar NULL significa que n„o foi possÌvel reservar o espaÁo
    printf("Memoria insuficiente!\n"); // informa o erro
    exit(1); // o programa È forÁado a sair da execuÁ„o da funÁ„o informando um erro de execuÁ„o
  }

  mat->linha = m; // variavel "linha" recebe o conteudo da variavel "m".
  mat->coluna = n; // variavel "coluna" recebe conteudo da variavel "n".
  mat->valor = (float*)malloc(m*n*sizeof(float)); // aloca memoria para o armazenamento da vari·vel "valor" de cada celula da matriz

  return mat; // retorna o valor apontado

}

// Observe a funcao e explique o funcionamento? Comente cada linha explicando cada item.
void libera(Matriz* mat){ // libera a memoria da matriz 

  free(mat->valor); // libera a memÛria que foi reservada para o armazenamento dos valores float* da matriz
  free(mat); // libera a memÛria que foi reservada para a matriz

}

// Observe a funcao e explique o funcionamento? Comente cada linha explicando cada item.
float acessa(Matriz* mat, int i, int j) { //FunÁ„o para acessar a matriz.

  int k; // declara uma vari·vel de tipo int

  if (i < 0 || i >= mat->linha || j < 0 || j >= mat->coluna) { // verifica se o valor da linha ou da coluna informado est· fora dos limites da matriz
    printf("Acesso invalido!\n"); //retorno de mensagem do if
    exit(1); // o programa È forÁado a sair da execuÁ„o da funÁ„o informando um erro de execuÁ„o
  }

  k = i * mat->coluna + j; // calcula a posiÁ„o onde o valor referenciado pela linha i e a coluna j È armazenado

  return mat->valor[k]; // retorna o valor apontado na matriz

}

// Observe a funcao e explique o funcionamento? Comente cada linha explicando cada item.
void atribui(Matriz* mat, int i, int j, float valor) { //funÁ„o para atribuir valores na matriz. Cast na Matriz para deixar valores com o mesmo tipo.

  int k; //declara uma variavel tipo inteira

  if (i < 0 || i >= mat->linha || j < 0 || j >= mat->coluna) { //condicional que identifica se a atribuiÁ„o È v·lida
    printf("Atribuicao invalida!\n"); //mensagem caso seja inv·lida
    exit(1); //o programa È forÁado a sair da execuÁ„o da funÁ„o informando um erro de execuÁ„o
  }

  k = i * mat->coluna + j; // calcula a posiÁ„o onde o valor referenciado pela linha i e a coluna j È armazenado

  mat->valor[k] = valor; // a posiÁ„o da matriz na linha e coluna informada recebe o valor atribuido a variavel "valor".

}

// Observe a funcao e explique o funcionamento? RESPOSTA: Retorna quantas linhas est„o inseridas na matriz 
int linhas(Matriz* mat){

  return mat->linha;

}

// Observe a funcao e explique o funcionamento? RESPOSTA: Retorna quantunas est„o inseridas na matriz
int colunas(Matriz* mat){ 

  return mat->coluna;

}

int main(){
  int resposta, linha, coluna;
  float valor;
  Matriz* m;

  printf("\nDeseja criar a matriz? \n 0 - NAO\n 1 - SIM \n");
  scanf("%d", &resposta);

  if(resposta == 1){
    printf("\nFavor informar o n˙mero de linhas da matriz: ");
    scanf("%d", &linha);
    printf("\nFavor informar o n˙mero de colunas da matriz: ");
    scanf("%d", &coluna);

    m = cria(linha, coluna);
    
    int acessar = 0;
    while(acessar != 6){
    printf("\n\nQUAL FUN«AO DA MATRIZ DESEJA ACESSAR? \n 1-Numero de linhas \n 2-Numero de colunas \n 3-Atribuir um valor \n 4-Extremidades da matriz\n 5-Impress„o da diagonal secund·ria\n 6-Sair\n");
    scanf("%d", &acessar);
    
      switch(acessar)
      {
        case 1:
          printf("\n O n˙mero de linhas da matriz criada È: %d", linhas(m));
          break;
        case 2:
          printf("\nO n˙mero de colunas da matriz criada È: %d", colunas(m));
          break;
        case 3:
          printf("\nFavor informar o n˙mero da linhas da matriz do valor a inserir: ");
          scanf("%d", &linha);
          printf("\nFavor informar o n˙mero da coluna da matriz do valor a inserir: ");
          scanf("%d", &coluna);
          printf("\nFavor informar o valor a inserir: ");
          scanf("%f", &valor);
          atribui(m, linha - 1, coluna - 1, valor);
          break;
        case 4: 
          printf("\n === VALORES DAS EXTREMIDADES DA MATRIZ ===");          
          printf("\nO valor na posiÁ„o 1,1 È :%f ", acessa(m, 0, 0));
          printf("\nO valor na posiÁ„o 1,%d È :%f ", m->coluna, acessa(m, 0, m->coluna - 1));
          printf("\nO valor na posiÁ„o %d,1 È :%f ", m->linha, acessa(m, m->linha - 1, 0));
          printf("\nO valor na posiÁ„o %d,%d È :%f ", m->linha, m->coluna, acessa(m, m->linha - 1, m->coluna - 1));
          break;        
        case 5:
          printf("\n === VALORES DA DIAGONAL SECUNDARIA DA MATRIZ ===");          
          if(m->coluna == m->linha) { //verifica se o numero de linhas È igual o de colunas
            int contadorColuna = m->coluna - 1; 
            for(int contador = 0; contador < m->linha; contador++) {       
              printf("\nO valor na posiÁ„o %d,%d È :%f ", contador + 1, contadorColuna + 1, acessa(m, contador, contadorColuna));
              contadorColuna--;
            }  
          } else {
            printf("\nA matriz nao eh quadrada!");
          }
          break;    
        default:
          printf("\nOpcao invalida");
          break;
      }
    }
  }

  libera(m);

  return 0;
}	

/*
Comente o codigo explicando as funcoes conforme solicitado.
O codigo devera ser apresentado e explicado pelo grupo em aula.
Implemente a main de forma que todas as funcoes sejam utilizadas amplamente pelo usuario.
Ao executar o programa deve ser solicitado ao usuario se deseja criar a matriz: 
  SIM: 
    -Executar a funcao de criacao da matriz. ok
    -Em seguida deve abrir um menu que permita utilizar amplamente as demais funcoes. ok
    -Implemente uma opcao que imprime as quatro extremidades da matriz. ok
    -Implemente a opcao especifica de seu grupo. ok
    -O programa devera executar ate que o usuario escolha a opcao sair, liberando a memoria e encerrando a execucao do programa. ok
  NAO: 
    -Encerrar a execucao do programa.


Grupo 2:
-Implemente uma opcao que imprime somente os valores da diagonal secundaria, essa opcao somente pode funcionar se for  matriz quadrada quando a quantidade de linhas e colunas sao iguais.


*/