#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "sequencia.h"

/* ===================================================================
 * arquivo.h
 * Funcoes de persistencia em arquivo de texto (PARTE III).
 *
 * Formato do arquivo "sequencias.txt":
 *   linha 1: nome da sequencia 1
 *   linha 2: DNA da sequencia 1
 *   linha 3: nome da sequencia 2
 *   linha 4: DNA da sequencia 2
 *   ...
 * =================================================================== */

#define ARQUIVO_PADRAO "sequencias.txt"

/**
 * Salva todas as sequencias do banco no arquivo "sequencias.txt".
 * Sobrescreve qualquer conteudo anterior.
 *
 * @param banco  Vetor de sequencias a salvar.
 * @param total  Quantidade de sequencias.
 */
void salvarArquivo(Sequencia *banco, int total);

/**
 * Carrega sequencias do arquivo "sequencias.txt" para o banco.
 * Substitui o conteudo atual do banco.
 *
 * @param banco  Vetor de sequencias (sera preenchido).
 * @param total  Ponteiro para o contador (sera atualizado).
 */
void carregarArquivo(Sequencia *banco, int *total);

#endif /* ARQUIVO_H */
