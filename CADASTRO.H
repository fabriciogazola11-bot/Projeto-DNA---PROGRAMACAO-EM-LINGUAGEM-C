#ifndef CADASTRO_H
#define CADASTRO_H

#include "sequencia.h"

/* ===================================================================
 * cadastro.h
 * Funcoes da PARTE I (Basico): cadastrar, listar, validar.
 * =================================================================== */

/**
 * Valida se uma sequencia contem apenas bases A, T, C, G (maiusculas).
 *
 * @param dna  String com a sequencia a ser validada.
 * @return     1 se valida, 0 caso contrario.
 */
int sequenciaValida(char *dna);

/**
 * Verifica se ja existe sequencia com o nome informado.
 *
 * @param banco  Vetor de sequencias cadastradas.
 * @param total  Quantidade de sequencias cadastradas.
 * @param nome   Nome a verificar.
 * @return       1 se ja existe, 0 caso contrario.
 */
int nomeJaExiste(Sequencia *banco, int total, char *nome);

/**
 * Cadastra uma nova sequencia no banco.
 * Solicita os dados ao usuario e valida antes de incluir.
 *
 * @param banco  Vetor de sequencias.
 * @param total  Ponteiro para o contador de sequencias (sera incrementado).
 */
void cadastrarSequencia(Sequencia *banco, int *total);

/**
 * Lista todas as sequencias cadastradas em formato de tabela.
 *
 * @param banco  Vetor de sequencias.
 * @param total  Quantidade de sequencias cadastradas.
 */
void listarSequencias(Sequencia *banco, int total);

/**
 * Busca uma sequencia pelo nome e retorna seu indice.
 *
 * @param banco  Vetor de sequencias.
 * @param total  Quantidade de sequencias cadastradas.
 * @param nome   Nome a buscar.
 * @return       Indice da sequencia ou -1 se nao encontrada.
 */
int buscarPorNome(Sequencia *banco, int total, char *nome);

#endif /* CADASTRO_H */
