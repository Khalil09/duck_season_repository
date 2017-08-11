#include<bits/stdc++.h>

using namespace std;

int v[500000];

// Funcao pesquisa binaria =====
bool binary_search(int x, int n){
    int a = 0;
    int b = n;
    int c;

    while(a <= b){
        c = (b+a)/2;
        if(v[c] == x) return true;
        if(v[c] < x)  a = c+1;
        else b = c-1;
    }
    return false;
}
//=============================

int main(){

    int n = 500;

    for(int i = 0; i < 500; i++){
        v[i] = i;
    }
    cout << binary_search(6, n) << endl;

}
