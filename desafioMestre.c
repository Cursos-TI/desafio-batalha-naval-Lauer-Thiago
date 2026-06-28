#include <stdio.h>

int main() {
    // ---- 1. CRIAÇÃO E INICIALIZAÇÃO DO TABULEIRO 10x10 ----
    int tabuleiro[10][10] = {0};

    // Posicionando os navios do nível anterior (representados pelo valor 3)
    // Navio Horizontal
    tabuleiro[1][2] = 3; tabuleiro[1][3] = 3; tabuleiro[1][4] = 3;
    // Navio Vertical
    tabuleiro[4][1] = 3; tabuleiro[5][1] = 3; tabuleiro[6][1] = 3;
    // Navio Diagonal 1
    tabuleiro[3][3] = 3; tabuleiro[4][4] = 3; tabuleiro[5][5] = 3;
    // Navio Diagonal 2
    tabuleiro[2][7] = 3; tabuleiro[3][6] = 3; tabuleiro[4][5] = 3;


    // ---- 2. CRIAÇÃO DINÂMICA DAS MATRIZES DE HABILIDADE (5x5) ----
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // O centro de uma matriz 5x5 para as coordenadas de origem é a posição [2][2]
    int centro = 2; 

    // Loop aninhado para gerar as formas geometricamente por meio de condições
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            
            // A. Lógica do Cone (linhas de 2 a 4, expandindo as colunas para os lados)
            if (r >= centro) {
                int espalhamento = r - centro;
                if (c >= (centro - espalhamento) && c <= (centro + espalhamento)) {
                    cone[r][c] = 1;
                }
            }

            // B. Lógica da Cruz (basta estar na mesma linha ou coluna do centro)
            if (r == centro || c == centro) {
                cruz[r][c] = 1;
            }

            // C. Lógica do Octaedro/Losango (distância absoluta combinada até o centro deve ser <= 1)
            int dist_linha = (r >= centro) ? (r - centro) : (centro - r);
            int dist_coluna = (c >= centro) ? (c - centro) : (centro - c);
            if ((dist_linha + dist_coluna) <= 1) {
                octaedro[r][c] = 1;
            }
        }
    }


    // ---- 3. INTEGRAR E SOBREPOR AS HABILIDADES NO TABULEIRO ----
    
    // Definição manual dos pontos de origem (alvos) de cada habilidade no tabuleiro 10x10
    int origem_cone_l = 2, origem_cone_c = 5;
    int origem_cruz_l = 7, origem_cruz_c = 3;
    int origem_octa_l = 7, origem_octa_c = 8;

    // Sobreposição do Cone
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (cone[r][c] == 1) {
                // Mapeia a posição 5x5 para a coordenada correspondente do tabuleiro 10x10
                int l_tab = origem_cone_l + (r - centro);
                int c_tab = origem_cone_c + (c - centro);
                
                // Validação de segurança: garante que a área de efeito não saia das bordas do tabuleiro
                if (l_tab >= 0 && l_tab < 10 && c_tab >= 0 && c_tab < 10) {
                    tabuleiro[l_tab][c_tab] = 5; // Aplica o efeito da habilidade (5)
                }
            }
        }
    }

    // Sobreposição da Cruz
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (cruz[r][c] == 1) {
                int l_tab = origem_cruz_l + (r - centro);
                int c_tab = origem_cruz_c + (c - centro);
                
                if (l_tab >= 0 && l_tab < 10 && c_tab >= 0 && c_tab < 10) {
                    tabuleiro[l_tab][c_tab] = 5;
                }
            }
        }
    }

    // Sobreposição do Octaedro
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (octaedro[r][c] == 1) {
                int l_tab = origem_octa_l + (r - centro);
                int c_tab = origem_octa_c + (c - centro);
                
                if (l_tab >= 0 && l_tab < 10 && c_tab >= 0 && c_tab < 10) {
                    tabuleiro[l_tab][c_tab] = 5;
                }
            }
        }
    }


    // ---- 4. EXIBIÇÃO DO TABULEIRO COMPLETO ----
    printf("=== BATALHA NAVAL: ÁREAS DE EFEITO ===\n");
    printf("Legenda: 0 = Agua | 3 = Navio | 5 = Habilidade\n\n");

    // Imprime índices das colunas para melhor usabilidade
    printf("    ");
    for (int col = 0; col < 10; col++) {
        printf("%d ", col);
    }
    printf("\n    -------------------\n");

    // Loops aninhados para imprimir a matriz 10x10 finalizada
    for (int i = 0; i < 10; i++) {
        printf("%d | ", i); // Índice da linha
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
