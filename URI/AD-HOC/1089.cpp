/* Utilizei 2 vetores um para guardar as magnitudes e outro para guardar
   a mundaça de valor. Sempre que um numero era maior atribuia 1 no vetor
   e quando era menor colocava 2, assim sempre que passava de 1 para 2 ou
   ao contrário significa que ali existe um pico
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, numb;
    int mag[10000];
    int picos[10000];
    int numb_picos = 0;
    int menor, maior;

    maior = menor = 0;

    scanf("%d", &n);

    while (n > 0) {
        numb_picos = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &mag[i]);
        }
        for (int i = 0; i < n-1; i++) {
            if (mag[i+1] < mag[i])
                picos[i] = 1;
            else
                picos[i] = 2;
        }
        if (mag[0] < mag[n-1])
            picos[n-1] = 1;
        else
            picos[n-1] = 2;

        for (int i = 0; i < n-1; i++) {
            if (picos[i+1] != picos[i])
                numb_picos++;
        }
        if (picos[0] != picos [n-1])
            numb_picos++;

        printf("%d\n", numb_picos);
        scanf("%d", &n);
    }


    return 0;
}
