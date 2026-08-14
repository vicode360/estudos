
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;
    printf("digite um umero: ");
    scanf(" %d", &x);

    x = x%2==0 ? printf("e par") : printf("e impa");
}