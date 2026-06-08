#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

int main() {
    float stack[MAXSIZE];
    int n = 0; // init
    char expressao[50];
    while (scanf(" %s", expressao) == 1) {
        if (strcmp(expressao, "q") == 0) {
            break;
        }
        float x;
        if (sscanf(expressao, "%f", &x) == 1) {
            assert(n<MAXSIZE);
            stack[n++] = x; // push
        }else {
            for (int i = 0; i <strlen(expressao); i++) {
                char c = expressao[i];
                assert(c == '+' || c == '-' || c == '*' || c == '/');
                assert(n>=2);
                float b = stack[--n];
                float a = stack[--n];
                if ( c == '+') stack[n++] = a + b;
                else if ( c == '-') stack[n++] = a - b;
                else if ( c == '*') stack[n++] = a * b;
                else if ( c == '/') stack[n++] = a / b;
            }
        }
    }
    if (n>0) printf("%g\n", stack[n-1]);
}