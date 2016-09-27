/* A meneira com que esse algoritmo eh feito eh baseado em setores e triangulos
   achados dentro do quadrado e semi-esferas */
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

#define PI (3.141592653589793)

int main() {
    double a, setor, af, ac, acc, as;

    while(scanf("%lf", &a) != EOF){
        setor = (a*a*PI)/6 - (sqrt(3)*a*a)/4;

        af = (a*a*PI)/12 - setor;

        ac = (a*a) - (af*4);

        acc =  (a*a) - (a*a*PI)/4 - af;

        as =  ((a*a) - (a*a*PI)/4) - (2*acc);

        printf("%.3lf %.3lf %.3lf\n", ac, 4*as, 4*acc);
    }
    return 0;
}
