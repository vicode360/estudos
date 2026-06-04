#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ALTURA 11
#define LARGURA 11

typedef int Labirinto[ALTURA][LARGURA];

void labirinto(Labirinto L) {
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            L[i][j] = 0; // Comeca como parede.
        }
    }
}

void imprimir_labirinto(Labirinto L) {
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (L[i][j] == 0) {
                printf("##");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

typedef struct {
    int x, y;
}Posicao;

//verificar se as coordenadas estao dentro dos limites
bool eh_valido(Posicao p) {
    return (p.x > 0 && p.x < LARGURA - 1 && p.y > 0 && p.y < ALTURA - 1);
}

//troca duas posicoes
void troca(Posicao *p, Posicao *q) {
    Posicao aux = *p;
    *p = *q;
    *q = aux;
}

void gerar_labirinto(int x, int y, Labirinto L) {
    L[x][y] = 1; // marca como caminho

    //vizinhos
    Posicao v[4] = {{x, y+2}, {x, y-2}, {x+2, y}, {x-2, y}};

     //embaralha os vizinhos para garantir aleatoriedade
     for (int i = 0; i < 4; i++) {
         int j = rand()%4;
         troca(&v[i], &v[j]);
     }
    for (int i = 0; i < 4; i++) {
        Posicao p = v[i];
        // Se a celula destino for valida e ainda for parede
        if (eh_valido(p) && L[p.x][p.y] == 0) {
            // Remove a parede entre a celula atual e a proxima
            L[(y + p.y)/2][(x + p.x)/2] = 1;

            // chamada recursiva para a nova celula
            gerar_labirinto(p.x, p.y, L);
        }
    }
}


int main() {
    srand(time(NULL));
    Labirinto L;
    labirinto(L);

    //inicia a geracao a partir da coordenada (1, 1)
    gerar_labirinto(1, 1, L);

    //Definir entrada e saida
    L[1][0] = 1;
    L[ALTURA - 2][LARGURA - 1] = 1;

    imprimir_labirinto(L);

}