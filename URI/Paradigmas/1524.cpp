#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k, a, sum, i = 1;
    vector<int> v;
    vector<int> aux;

    while(cin >> n >> k){
        v.push_back(0);
        aux.push_back(0);

        for(i = 1; i< n; i++){
            cin >> a;
            aux.push_back(a);
            v.push_back((aux[i] - aux[i-1]));
        }

        sort(v.rbegin(), v.rend());

        sum = 0;
        for(int l = k-1; l < n; l++){
            sum += v[l];
        }

        cout << sum << endl;
        v.clear();
        aux.clear();

    }

    return 0;
}
