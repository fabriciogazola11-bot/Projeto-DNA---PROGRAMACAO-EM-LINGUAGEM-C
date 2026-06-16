#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUTOS 1000
#define MAX_NOME 31
#define MAX_CUPONS 1000
#define MAX_ITENS_CUPOM 100

typedef struct {
    int codigo;
    long long preco;
    char nome[MAX_NOME];
    long long total_vendido;
} Produto;

typedef struct {
    int codigo;
    long long qtd;
} ItemCupom;

typedef struct {
    int n_itens;
    ItemCupom itens[MAX_ITENS_CUPOM];
} CupomFiscal;

Produto catalogo[MAX_PRODUTOS];
int n_produtos;

CupomFiscal lista_cupons[MAX_CUPONS];
int n_cupons;

/* Busca produto pelo codigo; retorna o indice correspondente ou -1 */
int busca(int codigo) {
    for (int i = 0; i < n_produtos; i++) {
        if (catalogo[i].codigo == codigo)
            return i;
    }
    return -1;
}

/* Converte os centavos para string no formato brasileiro R$ x,yy */
void formata_preco(long long centavos, char *buf) {
    long long reais = centavos / 100;
    long long cents = centavos % 100;
    if (cents < 0) cents = -cents; 
    sprintf(buf, "R$ %lld,%02lld", reais, cents);
}

/* Substitui o caractere '_' por ' ' no nome do produto */
void nome_exibicao(const char *src, char *dst) {
    int i;
    for (i = 0; src[i] && i < MAX_NOME - 1; i++) {
        dst[i] = (src[i] == '_') ? ' ' : src[i];
    }
    dst[i] = '\0';
}

/* Função de ordenação do qsort para o ranking */
int cmp_vendidos(const void *a, const void *b) {
    const Produto *pa = (const Produto *)a;
    const Produto *pb = (const Produto *)b;
    
    if (pb->total_vendido != pa->total_vendido) {
        return (pb->total_vendido > pa->total_vendido) ? 1 : -1;
    }
    return pa->codigo - pb->codigo;
}

int main(void) {
    // 1. LEITURA DE TODOS OS DADOS
    if (scanf("%d", &n_produtos) != 1) return 0;
    
    for (int i = 0; i < n_produtos; i++) {
        scanf("%d %lld %s",
              &catalogo[i].codigo,
              &catalogo[i].preco,
              catalogo[i].nome);
        catalogo[i].total_vendido = 0;
    }

    if (scanf("%d", &n_cupons) != 1) return 0;

    for (int c = 0; c < n_cupons; c++) {
        if (scanf("%d", &lista_cupons[c].n_itens) != 1) return 0;
        
        for (int i = 0; i < lista_cupons[c].n_itens; i++) {
            scanf("%d %lld", 
                  &lista_cupons[c].itens[i].codigo, 
                  &lista_cupons[c].itens[i].qtd);
        }
    }

    // 2. IMPRESSÃO DOS CUPONS
    for (int c = 0; c < n_cupons; c++) {
        printf("=== CUPOM %04d ===\n", c + 1);
        long long total_cupom = 0;

        for (int i = 0; i < lista_cupons[c].n_itens; i++) {
            int codigo = lista_cupons[c].itens[i].codigo;
            long long qtd = lista_cupons[c].itens[i].qtd;

            int idx = busca(codigo);
            if (idx != -1) {
                long long subtotal = catalogo[idx].preco * qtd;
                total_cupom += subtotal;
                catalogo[idx].total_vendido += qtd; 

                char exib[MAX_NOME];
                nome_exibicao(catalogo[idx].nome, exib);

                char preco_str[40], sub_str[40];
                formata_preco(catalogo[idx].preco, preco_str);
                formata_preco(subtotal, sub_str);

                // Máscara da linha 25 do PDF
                printf("%-20.20s %3lldx %10s %12s\n",
                       exib, qtd, preco_str, sub_str);
            }
        }

        char total_str[40];
        formata_preco(total_cupom, total_str);
        // Máscara do TOTAL da linha 29 do PDF
        printf("%-38s%12s\n", "TOTAL", total_str);
        printf("\n"); 
    }

    /* Geração e ordenação do Ranking */
    Produto vendidos[MAX_PRODUTOS];
    int nv = 0;
    for (int i = 0; i < n_produtos; i++) {
        if (catalogo[i].total_vendido > 0) {
            vendidos[nv++] = catalogo[i];
        }
    }

    qsort(vendidos, nv, sizeof(Produto), cmp_vendidos);

    printf("=== MAIS VENDIDOS ===\n");
    int lim = (nv < 3) ? nv : 3;
    
    for (int i = 0; i < lim; i++) {
        char exib[MAX_NOME];
        nome_exibicao(vendidos[i].nome, exib);
        
        // CORREÇÃO DA MÁSCARA: %do%-20.20s %41lld un.
        // O corretor exige exatamente o alinhamento correto baseado no tamanho de colunas (23 caracteres do início + 27 do modificador para fechar 50)
        // Reduzimos o modificador para %27lld para ajustar o alinhamento de acordo com o tamanho fixo da string anterior.
        printf("%do%-20.20s %27lld un.\n",
               i + 1, exib, vendidos[i].total_vendido);
    }

    return 0;
}
