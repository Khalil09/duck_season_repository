#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> l;
ll dp[1000006];
int M, n;	

ll blocos(int w){
	int j, i;

	if(w % l[n-1] == 0) return w / l[n-1];

	for(int k = 0; k < 1000006; k++){
		dp[k] = 1000006;
	}

	dp[0] = 0;

	for(int i = 0; i < n; i++){
		for(int j = l[i]; j <= w; j++){
			dp[j] = min(dp[j], dp[j-l[i]] + 1);
		}
	}

	return dp[w];
}

int main(){
	int t;

	cin >> t;

	while(t--){
		l.clear();
		
		memset(dp, -1, sizeof(dp));

		cin >> n >> M;
		for(int i = 0; i < n; i++){
			int a;
			cin >> a;
			l.push_back(a);
		}
		sort(l.begin(), l.end());
		cout << blocos(M) << endl;
		
	}
	return 0;
}