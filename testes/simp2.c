// Uma loja vende 4 tipos de produtos. Os produtos possuem código (formato pela letra P
// seguido de 3 algarismo numérico), quantidade em estoque e data de validade. O do no da loja
// tem um arquivo texto no seu computador chamado produtos.txt. O formato do arquivo é:
// P001 2100 10/12/2026
// P002 3400 20/01/2027
// P003 1200 21/03/2028
// P004 890 31/01/2026
//
// O dono da loja recebe um arquivo texto com a movimentação das 4 lojas que vendem seus
// produtos. O formato do arquivo texto recebido é: código do produto, quantidade vendida, dia
// da venda (dd/mm/aaaa) e código da loja. Use o arquivo movimento.txt fornecido.
//
// Fazer um programa para:
//
// 1. Imprimir na tela, os produtos mais vendidos
// 2. Imprimir na tela, os produtos com menos venda
// 3. Imprimir na tela, a quantidade vendida de cada produto
// 4. Imprimir na tela, a quantidade de cada produto vendido por todas as lojas
// 5. Imprimir na tela, o produto mais vendido e menos vendido por cada loja
// 6. Imprimir a quantidade de produtos que ficaram abaixo do estoque, ou seja, se o
// estoque ficar negativo, deve-se enviar mensagem para que este produto seja reposto.
// 7. Que dia o produto P001 foi mais vendido
// 8. Que dia o produto P002 foi mais vendido
// 9. Que dia o produto P003 foi mais vendido
// 10. Que dia o produto P004 foi mais vendido
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct produto {
    char codigo[10], data_vend[15], loja[4];
    int vendidos;
};
struct vetor {
    char codigos[4][5];
    char lojas[5][5];
};

void prods_vendidos () {
    FILE *fp;
    struct produto p;
    struct vetor v = {{"P001", "P002", "P003", "P004"},{"L01", "L02", "L03", "L04"}};
    int total_vendas[4] = {0};
    int total_lojas[4] = {0};
    int indice_loja = -1;
    int indice_codigo = -1;    // -1 pois significa nao encontrado
    int vendas_por_loja[4][4] = {0};

    fp = fopen("movimento.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    while (fscanf(fp, "%s %d %s %s", p.codigo, &p.vendidos, p.data_vend, p.loja) != EOF) {
        for (int i = 0; i < 4; i++) {
           if (strcmp(p.codigo, v.codigos[i]) == 0) {
               indice_codigo = i;
               break;
           }
        }
        for (int i = 0; i < 4; i++) {
            if (strcmp(p.loja, v.lojas[i]) == 0) {
                indice_loja = i; // aqui eh se caso der hit ( strcmp == 0) ele vai pegar o valor de i e atribuir ao indice e logo da break
                break; // apos o break ele vai realizar a soma e dps atribuir ao vendas_por_loja
            }
            }
            if (indice_codigo != -1) {
                total_vendas[indice_codigo] += p.vendidos; //> a brisa aqui eh q fica tipo total_vendas[0] = total de p001 (pois o v.codigos[0] seria o p001)
                //e o total_vendas[1] = total de p002. e assim por diante
            }
            if (indice_loja != -1) {
                total_lojas[indice_loja] += p.vendidos;
            }
            if (indice_codigo != -1 && indice_loja != -1) {
                vendas_por_loja[indice_loja][indice_codigo] += p.vendidos;  // vai adicionar a quantidade de vendas pra cada casa que precisa
            } // no  final vai somando td nos enderecos certos
        } // exemplos:
                    // vendas_por_loja[0][0] += 50; |  vendas_por_loja[2][1] += 10;
                    // L01: 50  0   0   0           |  L01: 50   0   0   0
                    // L02: 0   0   0   0           |  L02:  0   0   0   0
                    // L03: 0   0   0   0           |  L03:  0  10   0   0
                    // L04: 0   0   0   0           |  L04:  0   0   0   0
                            // e assim por diante

    int maior = 0;
    for (int i = 0; i < 4; i++) {
        if (total_vendas[i] > total_vendas[maior]) { // assume q o maior eh o p001 (maior = 0)
            maior = i;            // e compara com total_vendas[0, 1, 2, 3 e 4]
        }                     // se for maior ele atualiza o maior pelo oq achou (i)
    }
    printf("prod mais vendido: %s\n", v.codigos[maior]);
    printf("total vendido: %d\n", total_vendas[maior]);
    int menor = 0;
    for (int i = 0; i < 4; i++) {
        if (total_vendas[i] < total_vendas[menor]) {
            menor = i;
        }
    }
    printf("prod menos vendido: %s\n", v.codigos[menor]);
    printf("total vendido: %d\n\n", total_vendas[menor]);
    for (int i = 0; i < 4; i++) {
        printf("Produto %s:\n", v.codigos[i]);
        for (int j = 0; j < 4; j++) {
            printf("Loja %s: %d uniddades\n", v.lojas[j], vendas_por_loja[i][j]);
        }
    }
}

int main() {
    prods_vendidos();
}




