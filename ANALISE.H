#ifndef ANALISE_H
#define ANALISE_H

#include "sequencia.h"

/* ===================================================================
 * analise.h
 * Funcoes de analise: contagem de bases, conteudo GC, busca de motif.
 * Cobre conteudo das PARTES I e II.
 * =================================================================== */

/**
 * Conta a ocorrencia de cada base na sequencia.
 * Os contadores sao retornados via ponteiros (parametros de saida).
 *
 * @param dna   Sequencia a analisar.
 * @param qtdA  Ponteiro onde sera armazenada a quantidade de A.
 * @param qtdT  Ponteiro onde sera armazenada a quantidade de T.
 * @param qtdC  Ponteiro onde sera armazenada a quantidade de C.
 * @param qtdG  Ponteiro onde sera armazenada a quantidade de G.
 */
void contarBases(char *dna, int *qtdA, int *qtdT, int *qtdC, int *qtdG);

/**
 * Calcula o conteudo GC (percentual de G+C) na sequencia.
 *
 * @param dna      Sequencia a analisar.
 * @param tamanho  Tamanho da sequencia.
 * @return         Percentual de GC (0.0 a 100.0).
 */
float calcularGC(char *dna, int tamanho);

/**
 * Menu interativo: solicita escolha de sequencia e exibe contagem de bases.
 *
 * @param banco  Vetor de sequencias.
 * @param total  Quantidade de sequencias cadastradas.
 */
void menuContarBases(Sequencia *banco, int total);

/**
 * Menu interativo: solicita escolha de sequencia e exibe conteudo GC.
 *
 * @param banco  Vetor de sequencias.
 * @param total  Quantidade de sequencias cadastradas.
 */
void menuCalcularGC(Sequencia *banco, int total);

/**
 * Busca todas as ocorrencias de um motif (padrao) na sequencia.
 * Exibe as posicoes encontradas e retorna a quantidade total.
 *
 * @param dna     Sequencia onde buscar.
 * @param padrao  Padrao a procurar.
 * @return        Numero de ocorrencias encontradas.
 */
int buscarMotif(char *dna, char *padrao);

/**
 * Menu interativo: solicita sequencia e padrao, busca o motif.
 *
 * @param banco  Vetor de sequencias.
 * @param total  Quantidade de sequencias cadastradas.
 */
void menuBuscarMotif(Sequencia *banco, int total);

#endif /* ANALISE_H */
