#include <stdio.h>

#define TAM_TABULEIRO 10 // Tamanho tabuleiro 10x10
#define TAM_NAVIO 3 // Tamanho navio 

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).

    int tabuleiro[TAM_TABULEIRO] [TAM_TABULEIRO] = {0};
   
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.

    int linhaHorizontal = 0, colunaHorizontal = 7; // Navio horizontal
    int linhaVertical = 2, colunaVertical = 9; // Navio vertical 
    int linhaDiagonal1 = 7, colunaDiagonal1 = 0; // Primeiro navio diagonal
    int linhaDiagonal2 = 6, colunaDiagonal2 = 4; // Segundo navio diagonal 
    

    // Posiciona o navio horizontal no tabuleiro
    if (colunaHorizontal + TAM_NAVIO <= 10) {
        for(int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3; // Coloca o navio sendo representado por '3'
    }
   } else {
    printf( " ***ERROR*** \n");
   }

  
   // Posiciona o navio vertical no tabuleiro
   if (linhaVertical + TAM_NAVIO <= 10) {
        for(int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaVertical + i][colunaVertical] = 3; // Coloca o navio sendo representado por '3'
        }
    printf( " ***ERROR*** \n");
   }

    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.



    //printf("    "); // Adiciona um espaço de indentação para alinhar as colunas
    //for (int i = 0; i < 10; i++) {
        //printf("%c ", 'A' + i); // Imprime as letras das colunas de A-J
    //}
    //printf("\n");
    //printf("\n");
    
    
    //for (int i = 0; i < 10; i++) {
        //printf("%2d  ", i + 1); // Imprime as linhas numeradas de 1-10
        //for (int j = 0; j < 10; j++) {
            //printf("%d ", tabuleiro[i][j]);
        //}
        //printf("\n");
    //}
 

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.

    // Posiciona o primeiro navio diagonal (da esquerda para a direita)
    if (linhaDiagonal1 + TAM_NAVIO <= 10 && colunaDiagonal1 + TAM_NAVIO <= 10) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = 3; // Coloca o navio sendo representado por '3'
        }
    } else {
        printf("***ERROR***: Não cabe o navio diagonal 1.\n");
    }

    // Posiciona o segundo navio diagonal (da direita para a esquerda)
    if (linhaDiagonal2 + TAM_NAVIO <= 10 && colunaDiagonal2 - TAM_NAVIO + 1 >= 0) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = 3; // Coloca o navio sendo representado por '3'
        }
    } else {
        printf("***ERROR***: Não cabe o navio diagonal 2.\n");
    }

    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.


    // Imprime as linhas numeradas e os valores do tabuleiro
    for (int i = 0; i < 10; i++) {
        printf("%2d  ", i + 1); // Imprime as linhas numeradas de 1 - 10
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe o valor da posição 0 ou 3
        }
        printf("\n"); // Nova linha após imprimir tabuleiro
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.

    int matrizCone[3][5] = {0};
    int matrizCruz[3][5] = {0};
    int matrizOctaedro[3][5] = {0};

    // Gerando a matriz Cone
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= i; j++) {
            matrizCone[i][j] = 1;
        }
    }

    // Gerando a matriz Cruz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 1 || j == 2) {  // Linha e coluna central
                matrizCruz[i][j] = 1;
            }
        }
    }

    // Gerando a matriz Octaedro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2 || (i == 1 && (j == 1 || j == 3)) || (i == 3 && (j == 1 || j == 3))) {
                matrizOctaedro[i][j] = 1;
            }
        }
    }

    // Posições de origem das habilidades no tabuleiro
    int linhaCone = 2, colunaCone = 2;
    int linhaCruz = 5, colunaCruz = 5;
    int linhaOctaedro = 7, colunaOctaedro = 7;

    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.

    // Aplica a habilidade Cone
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizCone[i][j] == 1) {
                int linha = linhaCone + i - 2;  // Ajusta o deslocamento
                int coluna = colunaCone + j - 2;  // Ajusta o deslocamento

                // Verifica se a célula está dentro dos limites do tabuleiro
                if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                    if (tabuleiro[linha][coluna] != 3) {  // Não afeta os navios
                        tabuleiro[linha][coluna] = 1;  // Marca a célula como afetada pelo cone
                    }
                }
            }
        }
    }

    // Aplica a habilidade Cruz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizCruz[i][j] == 1) {
                int linha = linhaCruz + i - 1;  // Ajusta o deslocamento
                int coluna = colunaCruz + j - 2;  // Ajusta o deslocamento

                // Verifica se a célula está dentro dos limites do tabuleiro
                if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                    if (tabuleiro[linha][coluna] != 3) {  // Não afeta os navios
                        tabuleiro[linha][coluna] = 1;  // Marca a célula como afetada pela cruz
                    }
                }
            }
        }
    }

    // Aplica a habilidade Octaedro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizOctaedro[i][j] == 1) {
                int linha = linhaOctaedro + i - 2;  // Ajusta o deslocamento
                int coluna = colunaOctaedro + j - 2;  // Ajusta o deslocamento

                // Verifica se a célula está dentro dos limites do tabuleiro
                if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                    if (tabuleiro[linha][coluna] != 3) {  // Não afeta os navios
                        tabuleiro[linha][coluna] = 1;  // Marca a célula como afetada pelo octaedro
                    }
                }
            }
        }
    }

    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    
    // Exibe o tabuleiro
    printf("Bem vindo ao jogo de batalha naval!\n");
    printf("Tabuleiro:\n");
    printf("\n");
    printf("    ");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%c ", 'A' + i); // Imprime as letras das colunas A-J
    }
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d  ", i + 1); // Imprime as linhas numeradas de 1-10
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);  
        }
        printf("\n");  // Nova linha após imprimir tabuleiro
    }

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
