#include <bits/stdc++.h>

using namespace std;

#define D(b) cout << "Debug:" << b << endl

int main(){
	int n, a, count = 0;
	vector<int> v(30);
	map<int, int> m;

	cin >> n;

	v[0] = 2;
	for(int i = 1; i < 30; i++){
		v[i] = v[i-1]*2;
	}

	while(n--){
		cin >> a;
		m.insert(pair<int, int>(a, a));
	}

	for(auto s : m){
		cout << s.first << endl;
	}
	for(auto g : m){
		for(auto h : v){
			int t = h - g.first;
			if(m.find(t) != m.end()){
				count++;
				D(t);
			}
		}
	}
	cout << count/2 << endl;
}