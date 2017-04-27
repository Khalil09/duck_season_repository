#include <bits/stdc++.h>

using namespace std;

int n, c;
vector<int> v;
long long dp[200005][2];

long long db(int i, bool a){
	if(i == n){
		return 0;
	}

	if(dp[i][a] != -1){
		return dp[i][a];
	}

	if(a){
		dp[i][a] = max(db(i+1, 1), db(i+1, 0) + v[i]);
		return dp[i][a];
	} else {
		dp[i][a] = max(db(i+1, 0), db(i+1, 1) - v[i] - c); 
		return dp[i][a];
	}

}

int main(){
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}

	memset(dp, -1, sizeof(dp));

	cout <<	db(0, 0) << endl;
	
	return 0;
}