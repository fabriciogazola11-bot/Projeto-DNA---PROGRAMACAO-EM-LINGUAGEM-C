#include <stdio.h>
#include "ordenacao.h"
#include "cadastro.h"   /* para usar listarSequencias() */

/* ===================================================================
 * ordenacao.c
 * Implementacao do algoritmo de ordenacao escolhido pelo grupo.
 * =================================================================== */

/* ---------- IMPLEMENTADO - ordenacao por tamanho crescente ----------
 *
 * Escolha UM dos tres algoritmos abaixo para implementar:
 *
 * 1) BUBBLE SORT (Bolha):
 *    - Dois lacos aninhados.
 *    - Compara pares adjacentes (banco[j].tamanho e banco[j+1].tamanho).
 *    - Se estiverem fora de ordem, troca os elementos.
 *    - A cada passagem, o maior "borbulha" para o final.
 *
 * 2) SELECTION SORT (Selecao):
 *    - Para cada posicao i, encontra o menor elemento de i+1 ate n-1.
 *    - Troca com a posicao i.
 *
 * 3) INSERTION SORT (Insercao):
 *    - Para cada posicao i, pega o elemento e insere-o na posicao
 *      correta entre os ja ordenados (0 ate i-1).
 *
 * IMPORTANTE: para trocar duas posicoes do vetor, voce precisa de uma
 * variavel auxiliar do tipo Sequencia:
 *
 *     Sequencia aux;
 *     aux = banco[j];
 *     banco[j] = banco[j + 1];
 *     banco[j + 1] = aux;
 * ---------------------------------------------------------------------- */
void ordenarPorTamanho(Sequencia *banco, int total) {

    for (int i = 0; i < total - 1; i++) {

        for (int j = 0; j < total - 1 - i; j++) {

            if (banco[j].tamanho > banco[j + 1].tamanho) {

                printf("Trocando %s com %s\n",
                    banco[j].nome,
                    banco[j + 1].nome);

                Sequencia aux = banco[j];
                banco[j] = banco[j + 1];
                banco[j + 1] = aux;
            }

            
        }
    }
}

/* ---------- IMPLEMENTADO: menu de ordenacao ---------- */
void menuOrdenar(Sequencia *banco, int total) {
    if (total < 2) {
        printf("\n>> E preciso ter pelo menos 2 sequencias para ordenar.\n");
        return;
    }

    printf("\nOrdenando %d sequencias por tamanho crescente...\n", total);
    ordenarPorTamanho(banco, total);
    printf(">> Ordenacao concluida.\n");

    listarSequencias(banco, total);
}
