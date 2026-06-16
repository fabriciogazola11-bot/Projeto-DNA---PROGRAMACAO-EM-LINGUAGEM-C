#ifndef COMPARACAO_H
#define COMPARACAO_H

#include "sequencia.h"

/* ===================================================================
 * comparacao.h
 * Comparacao entre sequencias usando distancia de Hamming (PARTE III).
 *
 * IMPORTANTE: as funcoes desta parte DEVEM receber as sequencias por
 * ponteiro (Sequencia *), aplicando o conteudo de ponteiros visto em
 * aula.
 * =================================================================== */

/**
 * Calcula a distancia de Hamming entre duas sequencias.
 * As sequencias DEVEM ter o mesmo tamanho.
 *
 * @param s1  Ponteiro para a primeira sequencia.
 * @param s2  Ponteiro para a segunda sequencia.
 * @return    Distancia de Hamming, ou -1 se os tamanhos forem diferentes.
 */
int distanciaHamming(Sequencia *s1, Sequencia *s2);

/**
 * Menu interativo: solicita duas sequencias, calcula a distancia
 * de Hamming e exibe o resultado e o percentual de similaridade.
 *
 * @param banco  Vetor de sequencias.
 * @param total  Quantidade de sequencias.
 */
void menuCompararSequencias(Sequencia *banco, int total);

#endif /* COMPARACAO_H */
