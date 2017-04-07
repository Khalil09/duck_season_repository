#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, f, r;
	vector<int> v(3, 0);
	map<int, int> map;

	while(scanf(" %d %d\n", &n, &m) == 2){
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}

		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				for(int k = 1; k <= m; k++){
					f = v[0]*i + v[1]*j + v[2]*k;
					map[f]++;
				}
			}
		}
		 r = 0;
		for(auto g : map){
			if(g.second != 1) r++;
		}

		if(r == 0) cout << "Lucky Denis!" << endl;
		else cout << "Try again later, Denis..." << endl;

		map.clear();
	}

	return 0;
}