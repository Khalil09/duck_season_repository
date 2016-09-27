/* Esse problema envolve achar as formula geral do volume de uma caixa para
   assim deriva-la encontrando uma funcao do segundo grau achando facilmente
   o ponto maximo. Os outros 2 valores sao 0.000 sempre e metade da largura da
   caixa */
#include <bits/stdc++.h>

using namespace std;

double c, l;
double f(double x){
    return 4*x*x*x - 2*c*x*x - 2*l*x*x + l*c*x;
}

pair<double, double> bask(){
    pair<double, double> tmp;

    tmp.first = (4*(c+l) + sqrt((4*(c+l)*(4*(c+l)) - 4*12*l*c)))/24;
    tmp.second = (4*(c+l) - sqrt((4*(c+l)*(4*(c+l)) - 4*12*l*c)))/24;

    return tmp;
}

int main(){
    c = l = 1.0;
    pair<double, double> tmp;
    double max1, min1;

    while (scanf("%lf %lf", &c, &l) == 2) {
        tmp = bask();

        if(f(tmp.first) < f(tmp.second)) swap(tmp.first, tmp.second);

        printf("%.3lf 0.000 %.3lf\n", tmp.first, min(l, c) / 2);
    }

    return 0;
}
