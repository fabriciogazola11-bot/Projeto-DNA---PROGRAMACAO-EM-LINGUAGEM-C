#include <stdio.h>
#include "sequencia.h"
#include "cadastro.h"
#include "analise.h"
#include "ordenacao.h"
#include "arquivo.h"
#include "comparacao.h"

/* ===================================================================
 * main.c
 * Analisador de Sequencias de DNA - Programa principal.
 *
 * Fatec Ourinhos - Tecnologia em Analise e Desenvolvimento de Sistemas
 * Disciplina: Linguagem de Programacao (Linguagem C)
 * =================================================================== */

void exibirCabecalho(void) {
    printf("\n");
    printf("=====================================================\n");
    printf("       ANALISADOR DE SEQUENCIAS DE DNA              \n");
    printf("       Fatec Ourinhos - ADS - Linguagem C           \n");
    printf("=====================================================\n");
}

void exibirMenu(int total) {
    printf("\n--- MENU PRINCIPAL (%d sequencia(s) cadastrada(s)) ---\n",
           total);
    printf("\n  [Parte I - Basico]\n");
    printf("    1 - Cadastrar sequencia\n");
    printf("    2 - Listar sequencias\n");
    printf("    3 - Contar bases (A, T, C, G)\n");
    printf("    4 - Calcular conteudo GC\n");
    printf("\n  [Parte II - Intermediario]\n");
    printf("    5 - Ordenar sequencias por tamanho\n");
    printf("    6 - Buscar motif (padrao)\n");
    printf("\n  [Parte III - Avancado]\n");
    printf("    7 - Salvar sequencias em arquivo\n");
    printf("    8 - Carregar sequencias de arquivo\n");
    printf("    9 - Comparar duas sequencias (Hamming)\n");
    printf("\n    0 - Sair\n");
    printf("\nEscolha: ");
}

int main(void) {
    Sequencia banco[MAX_SEQ];   /* vetor estatico de sequencias */
    int total = 0;              /* contador de sequencias       */
    int opcao;

    exibirCabecalho();

    do {
        exibirMenu(total);

        if (scanf("%d", &opcao) != 1) {
            printf(">> Entrada invalida. Digite um numero.\n");
            /* Limpa o buffer de entrada */
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1: cadastrarSequencia(banco, &total);  break;
            case 2: listarSequencias(banco, total);      break;
            case 3: menuContarBases(banco, total);       break;
            case 4: menuCalcularGC(banco, total);        break;
            case 5: menuOrdenar(banco, total);           break;
            case 6: menuBuscarMotif(banco, total);       break;
            case 7: salvarArquivo(banco, total);         break;
            case 8: carregarArquivo(banco, &total);      break;
            case 9: menuCompararSequencias(banco, total); break;
            case 0: printf("\n>> Encerrando o programa...\n");    break;
            default: printf("\n>> Opcao invalida! Escolha entre 0 e 9.\n");
        }

    } while (opcao != 0);

    printf("Ate a proxima!\n\n");
    return 0;
}
