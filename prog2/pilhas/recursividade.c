#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void f(int x){
    if(x < 1)
        return;
    printf("A");
    f(x-1);
    printf("B");
}

// x = 5
// AAAAABBBBB

void f1(int x) {
   for (int i = 0; i < x; i++) {
       printf("A");
   }
    for (int i = 0; i < x; i++) {
        printf("B");
    }
}

void f2(int x){
    if(x < 1)
        return;
    printf("A%d ", x);
    f2(x-1);
    printf("B%d ", x);
}

// x = 5;
// A5A4A3A2A1B1B2B3B4B5

void f3(int x) {
    for (int i = x; i >= 1; i--) {
        printf("A%d", i);
    }
    for (int i = 0; i < x; i++) {
        printf("B%d", i);
    }
}

void imprimeAsteriscos(int n){
    if(n == 0)
        return;

    printf("*");
    imprimeAsteriscos(n - 1);
}

// n = 5
// *****

void imprimeAsteriscos1(int n) {
    for (int i = 0; i < n; i++) {
        printf("*");
    }
}





float potencia(float x, float n) {
  if (n==0) {
      return 1;
  }if (n < 0){
      return 1/potencia(x, -n);
  }
  return x * potencia(x, n-1);
}
void f4(int x){
    if(x < 1)
        return;

    int a = rand()%1000;

    printf("A%d ", a);
    f4(x-1);
    printf("B%d ", a);
}



void f5(int x) {
    int memoria[x];
    for (int i = x; i >= 1; i--) {
        int a = rand()%1000;
        printf("A%d ", a);
        memoria[i] = a;
    }
    for (int i = 1; i <= x; i++) {
        printf("B%d ", memoria[i]);
    }
}

int main(){
    srand(time(NULL));

    float a = potencia(2.1, 0);
    float b = potencia(3.5, 2);
    float c = potencia(2.6, -3);
    f(5);
    printf("\n");
    f1(5);
    printf("\n");
    f2(5);
    printf("\n");
    f3(5);
    printf("\n");
    imprimeAsteriscos(5);
    printf("\n");
    imprimeAsteriscos1(5);
    printf("\n");
    f4(5);
    printf("\n");
    f5(5);

    printf("\n%g %g %g\n", a, b, c);
}
