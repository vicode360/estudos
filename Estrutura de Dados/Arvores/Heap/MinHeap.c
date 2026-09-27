#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int totalElementos = 0; 

int indiceFilhoEsq(int x) {
    int indice = (2 * x) + 1;
    if (x >= totalElementos || indice >= totalElementos)
        return -1;
    else
        return indice;
}

int indiceFilhoDir(int x) {
    int indice = (2 * x) + 2;
    if (x >= totalElementos || indice >= totalElementos)
        return -1;
    else
        return indice;
}

int indicePai(int x) {
    int indice = (int) floor((x-1)/2);
    if (indice < 0 || x >= totalElementos)
        return -1;
    else
        return indice;
}

void AjustarSubindo(int *heap, int pos) {
    if (pos != -1) { 
        int pai = indicePai(pos);
        if (pai != -1) {
            if (heap[pos] > heap[pai]) {
                int aux = heap[pos];
                heap[pos] = heap[pai];
                heap[pai] = aux;
                AjustarSubindo(heap, pai);
            }
        }
    }
}

void Inserir(int *heap, int x) {
    heap[totalElementos] = x;
    totalElementos++;
    AjustarSubindo(heap, totalElementos - 1);
}

void AjustarDescendo(int *heap, int pos) {
    if (pos != -1 && indiceFilhoEsq(pos) != -1) {
        int indiceMaiorFilho = indiceFilhoEsq(pos);
        if (indiceFilhoDir(pos) != -1 && 
            heap[indiceFilhoDir(pos)] > heap[indiceMaiorFilho])
            indiceMaiorFilho = indiceFilhoDir(pos);
            
        if (heap[indiceMaiorFilho] > heap[pos]) {
            int aux = heap[pos];
            heap[pos] = heap[indiceMaiorFilho];
            heap[indiceMaiorFilho] = aux;
            AjustarDescendo(heap, indiceMaiorFilho);
        }
    }
}

int Remover (int *heap) {
    if (totalElementos == 0)
        return -1;
    else {
        int retorno = heap[0];
        heap[0] = heap[totalElementos - 1];
        totalElementos--;
        AjustarDescendo(heap, 0);
        printf("elemento removido da heap: %d\n", retorno);
        return retorno;
    }
}

void Imprimir(int *heap){

    if (totalElementos == 0 ){
        printf("heap vazia\n");
        return;

    }
    for (int i = 0; i < totalElementos; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void menu(){
    printf("selecione uma opcao \n");
    printf("1- inserir elemento x na heap | 2- remover elemento |\n 3- imprimir na heap | 4 Sair\n");
}

int main(){
    int escolha, x;
    int heap[40];

    do{
    menu();
    scanf(" %d", &escolha);
        if(escolha == 1){
            printf("valor de x: ");
            scanf(" %d", &x);
            Inserir(heap, x);
        }
        else if(escolha == 2){
            Remover(heap);
        }
        else if(escolha == 3){
            Imprimir(heap);
        }
        else if(escolha == 4){
            break;
        }
        else{
            printf("digite um valor valido\n");
        }
    }while(1);

    return 0;
}