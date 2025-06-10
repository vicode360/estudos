#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int jogar = 1;
    do {
            int dificuldade;
            int ntentativas;
            int numerosecreto;
            srand((unsigned int) time(0));
            int random = rand();

            printf("|-------------------------|\n");
            printf("|   Jogo da Adivinhacao   |\n");
            printf("|-------------------------|\n");
            printf("|       Selecione         |\n");
            printf("|  O Nivel de Dificuldade |\n");
            printf("|-------------------------|\n");
            printf("|  |1| Facil  |2| Medio   |\n");
            printf("|     |3| Dificil         |\n");
            printf("|-------------------------|\n");
            scanf("%d", &dificuldade);
            switch(dificuldade){
                case 1:
                    ntentativas = 20;
                    numerosecreto = random % 50;
                    break;

                case 2:
                    ntentativas = 12;
                    numerosecreto = random % 75;
                    break;

                case 3:
                    ntentativas = 6;
                    numerosecreto = random % 150;
                    break;

                default:
                    printf("invalido");
                    break;
            }
            double pontos = 500.25;
            int jogardnv = 1;
            int acertou = 0;
            int pontcalc = 1;
        for(int i = 1; i <= ntentativas; i++) {

            int chute;

            printf("Tentativa %d de %d \n", i, ntentativas);
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
                acertou = 1;
                break;
            }
            else{
                printf("invalido");
                continue;
            }
            pontcalc++;
            double pontos = abs(pontos - pontcalc) - 25.3;
        }

        if (acertou == 1) {
        printf("Parabens, vc acertou, n = %d\n", numerosecreto);
        printf("sua pontuacao foi de: %.1f/500\n", pontos);
        } else {
            printf("Voce perdeu! n = %d\n", numerosecreto);
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