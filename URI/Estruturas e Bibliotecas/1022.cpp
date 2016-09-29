#include <bits/stdc++.h>

using namespace std;

void reduzir(int num, int den, int *a, int *b){
    int divisor;

    while (num % 2 == 0 && den % 2 == 0) {
        num /= 2;
        den /= 2;
    }

    divisor = 3;
    while (divisor <= num || divisor <= den) {
        while (num % divisor == 0 && den % divisor == 0) {
            num /= divisor;
            den /= divisor;
        }
        divisor += 2;
    }

    *a = num;
    *b = den;
}

int main(){

    int n, n1, n2, d1, d2;
    int rac[4], den, num, red_den, red_num;
    char d;
    char op;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %c%d %c%d %c%d", &n1, &d, &d1, &op, &n2, &d, &d2);

        if (op == '+') {
            num = n1*d2 + n2*d1;
            den = d1*d2;
        } else if (op == '-') {
            num = n1*d2 - n2*d1;
            den = d1*d2;
        } else if (op == '*') {
            num = n1*n2;
            den = d1*d2;
        } else {
            num = n1*d2;
            den = n2*d1;
        }
        reduzir(num, den, &red_num, &red_den);
        printf("%d/%d = %d/%d\n", num, den, red_num, red_den);
    }
}
