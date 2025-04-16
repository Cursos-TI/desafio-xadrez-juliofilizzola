#include <stdio.h>
#include <string.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.#include <stdio.h>

// Movimento recursivo da Torre: apenas para a direita

// Função recursiva da Torre
int moverTorreRec(int casas) {
    if (casas == 0) return 0;
    printf("Direita\n");
    return 1 + moverTorreRec(casas - 1);
}

// Função recursiva do Bispo com loops aninhados
int moverBispoRec(int vertical, int horizontal) {
    if (vertical == 0 || horizontal == 0) return 0;

    int pontos = 0;

    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < horizontal; j++) {
            printf("Cima Direita\n");
            pontos++;
            return pontos + moverBispoRec(vertical - 1, horizontal - 1);
        }
    }

    return pontos;
}

// Função recursiva da Rainha
int moverRainhaRec(int casas) {
    if (casas == 0) return 0;
    printf("Esquerda\n");
    return 1 + moverRainhaRec(casas - 1);
}

// Função com loops aninhados para o Cavalo
int moverCavalo() {
    printf("Cima Cima Direita\n");
    return 1; // um movimento padrão simplificado
}

// Função de movimentação baseada na escolha da peça
int movimentarPeca(char peca[10], int casas) {
    if (strcmp(peca, "Torre") == 0) {
        printf("Movimento da Torre:\n");
        return moverTorreRec(casas);
    } else if (strcmp(peca, "Bispo") == 0) {
        printf("Movimento do Bispo:\n");
        return moverBispoRec(casas, casas);
    } else if (strcmp(peca, "Rainha") == 0) {
        printf("Movimento da Rainha:\n");
        return moverRainhaRec(casas);
    } else if (strcmp(peca, "Cavalo") == 0) {
        printf("Movimento do Cavalo:\n");
        return moverCavalo();
    } else {
        printf("Peça inválida.\n");
        return 0;
    }
}

int main() {
    char jogador1[50], jogador2[50];
    char peca1[10], peca2[10];
    int casas1, casas2;

    // Entrada dos jogadores
    printf("Digite o nome do Jogador 1: ");
    scanf("%s", jogador1);
    printf("Escolha a peça (Torre, Bispo, Rainha, Cavalo): ");
    scanf("%s", peca1);
    printf("Digite o número de casas a mover: ");
    scanf("%d", &casas1);

    printf("\n");

    printf("Digite o nome do Jogador 2: ");
    scanf("%s", jogador2);
    printf("Escolha a peça (Torre, Bispo, Rainha, Cavalo): ");
    scanf("%s", peca2);
    printf("Digite o número de casas a mover: ");
    scanf("%d", &casas2);

    printf("\n");

    // Movimentação dos jogadores
    printf("Jogador 1 - %s:\n", jogador1);
    int pontos1 = movimentarPeca(peca1, casas1);

    printf("\nJogador 2 - %s:\n", jogador2);
    int pontos2 = movimentarPeca(peca2, casas2);

    // Determinar vencedor
    printf("\nResultado:\n");
    printf("%s fez %d movimentos.\n", jogador1, pontos1);
    printf("%s fez %d movimentos.\n", jogador2, pontos2);

    if (pontos1 > pontos2) {
        printf("Vencedor: %s\n", jogador1);
    } else if (pontos2 > pontos1) {
        printf("Vencedor: %s\n", jogador2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}