#include <stdio.h>
#include <string.h>
#include "arquivo.h"
#include "analise.h"

/* ===================================================================
 * arquivo.c
 * Implementacao das funcoes de salvar/carregar arquivo.
 * =================================================================== */

/* -------------------------------------------------------
 * Salva todas as sequencias cadastradas em um arquivo.
 *
 * A funcao cria ou sobrescreve o arquivo "sequencias.txt"
 * e grava os dados de cada sequencia armazenada no banco.
 *
 * Para cada sequencia sao salvos:
 *   - Nome da sequencia
 *   - Cadeia de DNA
 *
 * Ao final da operacao, o arquivo e fechado e uma
 * mensagem informa a quantidade de sequencias salvas.
 * ------------------------------------------------------- */
void salvarArquivo(Sequencia *banco, int total) {

    FILE *arq = fopen(ARQUIVO_PADRAO, "w");

    if (arq == NULL) {
        printf(">> Erro ao criar arquivo.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(arq, "%s\n", banco[i].nome);
        fprintf(arq, "%s\n", banco[i].dna);
    }

    fclose(arq);

    printf(">> %d sequencia(s) salva(s) com sucesso.\n", total);
}

/* -------------------------------------------------------
 * Carrega todas as sequencias salvas no arquivo.txt(texto).
 * -------------------------------------------------------
 * A funcao abre o arquivo "sequencias.txt", le os nomes
 * e as sequencias de DNA armazenadas e os insere no banco
 * de dados do sistema.
 *
 * Durante a leitura, tambem atualiza o tamanho de cada
 * sequencia e recalcula o conteudo GC.
 *
 * Caso o arquivo nao exista, uma mensagem de erro e exibida.
 * ------------------------------------------------------- */
void carregarArquivo(Sequencia *banco, int *total) {

    FILE *arq = fopen(ARQUIVO_PADRAO, "r");

    if (arq == NULL) {
        printf(">> Arquivo nao encontrado.\n");
        return;
    }

    *total = 0;

    while (*total < MAX_SEQ &&
           fgets(banco[*total].nome, TAM_NOME, arq) != NULL &&
           fgets(banco[*total].dna, TAM_DNA, arq) != NULL) {

        banco[*total].nome[
            strcspn(banco[*total].nome, "\n")
        ] = '\0';

        banco[*total].dna[
            strcspn(banco[*total].dna, "\n")
        ] = '\0';

        banco[*total].tamanho =
            strlen(banco[*total].dna);

        banco[*total].gc =
            calcularGC(
                banco[*total].dna,
                banco[*total].tamanho
            );

        (*total)++;
    }

    fclose(arq);

    printf(">> %d sequencia(s) carregada(s).\n", *total);
}
