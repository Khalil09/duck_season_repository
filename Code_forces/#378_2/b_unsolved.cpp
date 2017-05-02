#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int main(){

    int k, kaux, l, r;
    long long int lsum = 0, rsum = 0, maxlidx = 0, maxridx = 0, maxl = 0, maxr = 0,
    minRL = 100005, minLR = 100005;
    vector<ii> v;

    cin >> k;
    kaux = k;
    while(kaux--){
        cin >> l >> r;
        v.push_back(ii(l, r));
    }

    for(int i = 0; i < k; i++){
        lsum += v[i].first;
        rsum += v[i].second;
        if(v[i].first >= maxl){
            maxl = v[i].first;
            if (v[i].first == maxl) {
                if (v[i].second < minRL) {
                    minRL = v[i].second;
                    maxlidx = i;
                    continue;
                }
            }
            maxlidx = i;
        }
        if(v[i].second >= maxr){
            maxr = v[i].second;
            if (v[i].second == maxr) {
                if (v[i].first < minLR) {
                    minRL = v[i].first;
                    maxridx = i;
                    continue;
                }
            }
            maxridx = i;
        }
    }


    long long int trocaR, trocaL;
    trocaR = abs((lsum + v[maxridx].second - v[maxridx].first) - (rsum + v[maxridx].first - v[maxridx].second));
    trocaL = abs((lsum + v[maxlidx].second - v[maxlidx].first) - (rsum + v[maxlidx].first - v[maxlidx].second));

    if (trocaR <= abs(lsum - rsum) && trocaL <= abs(lsum - rsum)) {
        std::cout << 0 << '\n';
        return 0;
    }
    if (trocaR > trocaL) {
        cout << maxridx + 1 << '\n';
    }
    else{
        cout << maxlidx + 1 << '\n';
    }

    return 0;
}
