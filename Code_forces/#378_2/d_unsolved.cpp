#include <bits/stdc++.h>

using namespace std;

int min3(int a, int b, int c){
    int aux;
    if(a <= b){
        aux = a;
    } else {
        aux = b;
    }
    if(aux < c){
        return aux;
    } else {
        return c;
    }
}

int main(){
    int n;
    vector<int> v1, v2, v3;
    vector<int> m;

    cin >> n;
    int n2 = n;
    while(n--){
        int a, b, c;
        cin >> a >> b >> c;
        v1.push_back(a);
        v2.push_back(b);
        v3.push_back(c);
    }

    for(int i = 0; i < n2; i++){
        m.push_back(min3(v1[i], v2[i], v3[i]));
    }

    for(int i = 0; i < n2; i++){
        for(int j = 0; j < n2; j++){
            if(v1[i] == v1[j]){
                if(v2[i] == v2[j]){
                    m.push_back(v3[i] + v3[j]);
                } else if(v3[i] == v3[j]){
                    m.push_back(v2[i] + v3[j]);
                }
            }
        }
    }

    for(int i = 0; i < n2; i++){
        for(int j = 0; j < n2; j++){
            if(v2[i] == v2[j]){
                if(v3[i] == v3[j]){
                    m.push_back(v3[i] + v3[j]);
                } else if(v1[i] == v1[j]){
                    m.push_back(v2[i] + v3[j]);
                }
            }
        }
    }

    cout << *max_element(m.begin(), m.end()) << endl;
}
