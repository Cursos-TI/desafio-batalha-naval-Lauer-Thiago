#include <stdio.h>

// Definição das constantes para o tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Requisito: Matriz 10x10 inicializada com 0 (representando a água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (Definidas diretamente no código)
    // Navio Horizontal: ficará na linha 2, ocupando as colunas 3, 4 e 5
    int navio_h_linha = 2;
    int navio_h_coluna = 3;

    // Navio Vertical: ficará na coluna 6, ocupando as linhas 5, 6 e 7
    int navio_v_linha = 5;
    int navio_v_coluna = 6;

    // Variável de controle para validar o estado do posicionamento
    int posicionamento_valido = 1;

    printf("=== INSTALANDO NAVIOS NO TABULEIRO ===\n\n");

    // ==========================================
    // 1. VALIDAÇÃO DE LIMITES (Navio Horizontal)
    // ==========================================
    if (navio_h_linha < 0 || navio_h_linha >= TAMANHO_TABULEIRO ||
        navio_h_coluna < 0 || (navio_h_coluna + TAMANHO_NAVIO) > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro!\n");
        posicionamento_valido = 0;
    }

    // ==========================================
    // 2. VALIDAÇÃO DE LIMITES (Navio Vertical)
    // ==========================================
    if (navio_v_linha < 0 || (navio_v_linha + TAMANHO_NAVIO) > TAMANHO_TABULEIRO ||
        navio_v_coluna < 0 || navio_v_coluna >= TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro!\n");
        posicionamento_valido = 0;
    }

    // ==========================================
    // 3. POSICIONAMENTO E VALIDAÇÃO DE SOBREPOSIÇÃO
    // ==========================================
    if (posicionamento_valido) {
        
        // Posiciona o Navio Horizontal (atribuindo o valor 3)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio_h_linha][navio_h_coluna + i] = 3;
        }

        // Verifica se haverá sobreposição antes de colocar o Navio Vertical
        int sobrepôs = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio_v_linha + i][navio_v_coluna] == 3) {
                sobrepôs = 1;
                break;
            }
        }

        // Se não houver sobreposição, posiciona o Navio Vertical
        if (!sobrepôs) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[navio_v_linha + i][navio_v_coluna] = 3;
            }
            printf("Navios posicionados com sucesso!\n\n");
        } else {
            printf("Erro: Os navios estão se sobrepondo!\n\n");
            posicionamento_valido = 0;
        }
    }

    // ==========================================
    // 4. EXIBIÇÃO DO TABULEIRO
    // ==========================================
    // Só exibe o tabuleiro limpo ou atualizado se a lógica inicial rodar
    printf("  ");
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("%d ", col); // Cabeçalho visual das colunas
    }
    printf("\n");

    // Loops aninhados para renderizar a matriz de forma organizada
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        printf("%d ", linha); // Indicador visual da linha lateral
        
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            // Imprime o valor da posição com um espaço separador para melhor legibilidade
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n"); // Quebra de linha ao fim de cada linha da matriz
    }

    return 0;
}
