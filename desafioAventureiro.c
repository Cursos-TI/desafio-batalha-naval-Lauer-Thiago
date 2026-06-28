#include <stdio.h>

int main() {
    // ---- CRIAÇÃO E INICIALIZAÇÃO DO TABULEIRO ----
    // Declara uma matriz 10x10 e inicializa todas as posições com 0 (água)
    int tabuleiro[10][10] = {0};
    
    // Variável para verificar se todo o posicionamento ocorreu sem erros
    int validacao_ok = 1;

    // ---- POSICIONAMENTO E VALIDAÇÃO DOS NAVIOS (Tamanho 3) ----

    // Navio 1: Horizontal -> Linha 1, Colunas 2, 3 e 4
    // Valida se está dentro dos limites (0 a 9) e se as posições estão vazias (iguais a 0)
    if ((1 >= 0 && 1 < 10) && (2 >= 0 && 4 < 10)) {
        if (tabuleiro[1][2] == 0 && tabuleiro[1][3] == 0 && tabuleiro[1][4] == 0) {
            tabuleiro[1][2] = 3;
            tabuleiro[1][3] = 3;
            tabuleiro[1][4] = 3;
        } else {
            validacao_ok = 0; // Erro: Sobreposição
        }
    } else {
        validacao_ok = 0; // Erro: Fora dos limites
    }

    // Navio 2: Vertical -> Linhas 5, 6 e 7, Coluna 1
    if ((5 >= 0 && 7 < 10) && (1 >= 0 && 1 < 10)) {
        if (tabuleiro[5][1] == 0 && tabuleiro[6][1] == 0 && tabuleiro[7][1] == 0) {
            tabuleiro[5][1] = 3;
            tabuleiro[6][1] = 3;
            tabuleiro[7][1] = 3;
        } else {
            validacao_ok = 0;
        }
    } else {
        validacao_ok = 0;
    }

    // Navio 3: Diagonal 1 (Linha e coluna aumentam juntas) -> (3,3), (4,4), (5,5)
    if ((3 >= 0 && 5 < 10) && (3 >= 0 && 5 < 10)) {
        if (tabuleiro[3][3] == 0 && tabuleiro[4][4] == 0 && tabuleiro[5][5] == 0) {
            tabuleiro[3][3] = 3;
            tabuleiro[4][4] = 3;
            tabuleiro[5][5] = 3;
        } else {
            validacao_ok = 0;
        }
    } else {
        validacao_ok = 0;
    }

    // Navio 4: Diagonal 2 (Linha aumenta e coluna diminui) -> (2,7), (3,6), (4,5)
    if ((2 >= 0 && 4 < 10) && (5 >= 0 && 7 < 10)) {
        if (tabuleiro[2][7] == 0 && tabuleiro[3][6] == 0 && tabuleiro[4][5] == 0) {
            tabuleiro[2][7] = 3;
            tabuleiro[3][6] = 3;
            tabuleiro[4][5] = 3;
        } else {
            validacao_ok = 0;
        }
    } else {
        validacao_ok = 0;
    }

    // ---- EXIBIÇÃO DO STATUS DE VALIDAÇÃO ----
    if (validacao_ok) {
        printf(">>> Sucesso: Todos os navios posicionados dentro dos limites e sem sobreposicao! <<<\n\n");
    } else {
        printf(">>> Erro: Falha na validacao de limites ou sobreposicao de navios! <<<\n\n");
    }

    // ---- EXIBIÇÃO DO TABULEIRO (Loops Aninhados) ----
    // Imprime o cabeçalho com o índice das colunas para alinhar a visualização
    printf("    ");
    for (int c = 0; c < 10; c++) {
        printf("%d ", c);
    }
    printf("\n");
    
    // Linha divisória decorativa
    printf("    -------------------\n");

    // Loops aninhados para percorrer as linhas (i) e colunas (j) da matriz
    for (int i = 0; i < 10; i++) {
        printf("%d | ", i); // Imprime o índice da linha atual
        
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime o valor da célula (0 ou 3) com um espaço de alinhamento
        }
        printf("\n"); // Quebra de linha ao fim de cada linha da matriz
    }

    return 0;
}
