#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "sequencia.h"

/* ===================================================================
 * ordenacao.h
 * Funcoes de ordenacao das sequencias (PARTE II).
 *
 * O grupo deve implementar UM algoritmo de ordenacao a sua escolha
 * (Bolha, Selecao ou Insercao). Aqui esta a assinatura padrao.
 * =================================================================== */

/**
 * Ordena o vetor de sequencias por tamanho em ordem crescente.
 *
 * @param banco  Vetor de sequencias a ser ordenado.
 * @param total  Quantidade de sequencias no vetor.
 */
void ordenarPorTamanho(Sequencia *banco, int total);

/**
 * Menu interativo: ordena e lista o resultado.
 *
 * @param banco  Vetor de sequencias.
 * @param total  Quantidade de sequencias.
 */
void menuOrdenar(Sequencia *banco, int total);

#endif /* ORDENACAO_H */
