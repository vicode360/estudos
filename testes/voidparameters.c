#include <stdio.h>

void printpi(double p) {
    printf("valor de pi = %f\n", p);
}
void printintpi(int p_int) {
    printf("valor de pi int = %d", p_int);
}
int main() {
    int pint = 3;
    double pi = 3.14159265359;
    printpi(pi);
    printintpi(pint);
    return 0;
}
/* valor de pi = 3.141593
valor de pi int = 3
Process finished with exit code 0 */
