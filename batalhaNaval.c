#include <stdio.h>

#define TAM_TABULEIRO 10 // Tamanho tabuleiro 10x10
#define TAM_NAVIO 3 // Tamnho navio 

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).

    int tabuleiro[TAM_TABULEIRO] [TAM_TABULEIRO] = {0};
   
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.

    int linhaHorizontal = 4, colunaHorizontal = 4; // Navio horizontal
    int linhaVertical = 6, colunaVertical = 5; // Navio vertical 

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
            tabuleiro[linhaVertical + i][colunaVertical] = 3; // Coloca o navio (representado por 3)
        }
   } else {
    printf( " ***ERROR*** \n");
   }

    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Exibe o tabuleiro
    printf("Bem vindo ao jogo de batalha naval!\n");
    printf("Tabuleiro:\n");
    printf("\n");


    printf("    "); // Adiciona um espaço de indentação para alinhar as colunas
    for (int i = 0; i < 10; i++) {
        printf("%c ", 'A' + i); // Imprime as letras das colunas de A-J
    }
    printf("\n");
    printf("\n");
    
    
    for (int i = 0; i < 10; i++) {
        printf("%2d  ", i + 1); // Imprime as linhas numeradas de 1-10
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
 

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

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
