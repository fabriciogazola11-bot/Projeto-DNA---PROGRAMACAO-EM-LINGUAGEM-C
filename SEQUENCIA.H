#ifndef SEQUENCIA_H
#define SEQUENCIA_H

/* ===================================================================
 * sequencia.h
 * Definicoes da struct Sequencia e constantes globais do sistema.
 * =================================================================== */

/* ---- Limites do sistema ---- */
#define MAX_SEQ   10    /* Numero maximo de sequencias cadastradas    */
#define TAM_DNA  201    /* Tamanho maximo da sequencia + '\0'         */
#define TAM_NOME  31    /* Tamanho maximo do nome + '\0'              */

/* ---- Estrutura principal ---- */
typedef struct {
    char  nome[TAM_NOME];   /* nome identificador da sequencia        */
    char  dna[TAM_DNA];     /* a sequencia de DNA (string A/T/C/G)    */
    int   tamanho;          /* tamanho efetivo da sequencia           */
    float gc;               /* conteudo GC pre-calculado (cache)      */
} Sequencia;

#endif /* SEQUENCIA_H */
