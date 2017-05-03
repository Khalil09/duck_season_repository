#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

int i, a, n;
vector<int> p;
vector<int> u;
long long dpm[2001][50001];



int dp(int i, int t){
	if(i == 0 || t == 0){
		return 0;
	}
    if(dpm[i][t] != -1){
		return dpm[i][t];
	}
	if(p[i-1] > t){
        dpm[i][t] = dp(i-1, t);
		return dpm[i][t];
	} else {
        dpm[i][t] = max(u[i-1] + dp(i-1, t-p[i-1]), dp(i-1, t));
		return dpm[i][t];
	}

}

// long long dp(int i, int t){
//     if(i == n || t == 0){
//         return 0;
//     }
//
//     if(vec[i].first > t){
//         dpm[i][t] = dp(i+1, t);
//         return dpm[i][t];
//     } else {
//         dpm[i][t] = max(dp(i + 1, t), dp(i + 1, t-vec[i+1].second) + vec[i].first);
//         return dpm[i][t];
//     }
// }


int main(){

    int c, v, aux, tot;
    cin >> n >> tot;
    aux = n;
    while(n--){
        cin >> c >> v;
        p.push_back(c);
        u.push_back(v);
    }
    n = aux;
    memset(dpm, -1, sizeof(dpm));

    cout << dp(n, tot) << endl;

    return 0;

}
