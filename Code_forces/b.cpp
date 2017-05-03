#include <bits/stdc++.h>

using namespace std;

#define D(b) cout << "Debug:" << b << endl

int main(){
	long long int n, a, count = 0;
	vector<int> v(30);
	vector<int> V;
	map<int, int> m;

	cin >> n;

	v[0] = 2;
	for(int i = 1; i < 30; i++){
		v[i] = v[i-1]*2;
	}

	while(n--){
		cin >> a;
		m[a]++;
		V.push_back(a);
	}
	for(auto g : V){
		m[g]--;
		for(auto h : v){
			int t = h - g;
			if(m.find(t) != m.end()){
				count += m[t];
			}
		}
	}
	cout << count << endl;

	return 0;
}