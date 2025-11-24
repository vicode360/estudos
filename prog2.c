#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void palindromo(int vo[1000]){
int i = 0;
int vi[1000];
for (int j = 999; j >= 0; j--){
    vi[j] = vo[i];
    i++;
}for(int i=0; i<1000; i++){
 if(vo[i] != vi[i]){
    printf("nao eh\n");
    break;
    } if(i==999){
    printf("palindromo\n");}
}
}

void zero_ou_um(int vo[1000]){
int zero = 0, um =0;
for(int i = 0; i<1000; i++){
    if(vo[i] == 0){
        zero +=1;
    }else{um+=1;}
}
if (zero > um){
    printf("tem mais zero\n");
}else if( zero == um){
printf("igual\n");}
else{
    printf("mais um\n");
}
}
void soma_primo(int vo[1000]){
int soma = 0;
for(int i =0; i <1000; i++){
    soma+= vo[i];
}
printf("a soma eh %d, ", soma);
for(int i = 2; i<soma; i++){
    if(soma%i==0){
        printf("nao e primo\n");
        break;
    }
    if(i==(soma-1)){
        printf("e primo\n");
        break;
    }
}
}
void gravar(int vetor[1000]){
    int v[100][10];
    int a =0, b=0;
    while(b<1000){
        for(int i = 0; i <10; i++){
            v[a][i] = vetor[b];
            b++;
              if(i == 9){
            a++;
        }
        }
    }
FILE *fp;
fp = fopen("saida.txt", "w");
    if(fp==NULL){
        exit(1);
    }   for(int i = 0; i < 100; i++){
            for(int j=0; j<10; j++){
                fprintf(fp, "%d", v[i][j]);
            }fprintf(fp, "\n");
    }
}

void subsequencia(int vo[1000]){
int v=0, x;
int seq[4] = {0,1,0,1};
while(v<996){
    x = v;
    for(int i = 0; i<4; i++){
        if(vo[x] != seq[i]){
            v++;
            break;
        }
        if(i==3){
        printf("0101. .");
        v++;
    }
    x++;
}
}
}
void menu(){
printf("1- palindromo, 2 - zero ou um, 3- primo, 4-grava, 5- subsequencia\n");
}
int main(){
    int vetor[1000];
    int z, escolha;
    srand (time(NULL));
    for(int x = 0; x <1000; x++){
            z = rand() % 100;
                if(z%2 == 1){
                    vetor[x] = 1;
                }else{
                vetor[x] = 0;}
    }
    menu();
    scanf("%d", &escolha);
    switch(escolha){
case 1:
    palindromo(vetor);
    break;
case 2:
    zero_ou_um(vetor);
    break;
case 3:
    soma_primo(vetor);
    break;
case 4:
    gravar(vetor);
    break;
case 5:
    subsequencia(vetor);
    break;
default:
    break;
  }
}
