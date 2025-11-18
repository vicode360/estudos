#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {

    int jogar = 1;
    do {

            printf("--------------------------\n");
            printf("|   Jogo da Adivinhacao   |\n");
            printf("--------------------------\n");
            int jogando = 1;
            int seed = time(0);
            srand((unsigned int) seed);
            int numerotentativas = 1;
            int random = rand();
            int r = random % 101;
            int numerosecreto = r;
            double x = 500.25;
            int jogardnv = 1;

        while(jogando == 1) {

            int chute;

            printf("Tentativa %d \n", numerotentativas);
            printf("faca seu chute: ");
            scanf("%d", &chute);
            
            int maior = chute > numerosecreto;
            int menor = chute < numerosecreto;
            int acerto = chute == numerosecreto;

            if (maior) {
                printf("Seu chute foi maior que o numero secreto\n");
            }
            
            else if (menor) {
                printf("Seu chute foi menor que o numero secreto\n");
            }
            
            else if (acerto) {
                printf("Parabens, vc acertou, n = %d\n", r);
                printf("sua pontuacao foi de: %.1f/500\n", x);
                jogando = 0;
            }
            else{
                printf("invalido");
                continue;
            }
            numerotentativas++;
            x = (double)(x - numerotentativas) - (double)25;
        }
        while(jogardnv == 1){
            char resposta;
            printf("Deseja jogar novamente? (S/N)\n");
            scanf(" %c", &resposta);
            
            if (resposta == 'S' || resposta == 's') {
                jogardnv = 0;
                continue;
            }
            
            if (resposta == 'N' || resposta == 'n') {
                jogar = 0;
                break;
            }
            else {
                printf("comando invalido \n");
                jogardnv = 1;
                continue;
            }
        }
    } while(jogar == 1);
    
    printf("Fim do jogo\n");
    return 0;
}
