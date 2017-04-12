#include <bits/stdc++.h>

using namespace std;

#define D(a) cout << "Debug: " << a << endl;

vector<int> minf;
vector<int> maxf;

pair<int, int> closests(vector<int> ocp, int j){
	int i, f = 0, s = 0;
	
	for(i = j; ocp[i] != 1; i++, s++);
	for(i = j; ocp[i] != 1; i--, f++);

	return make_pair(f-1, s-1);
}

int main(){
	int t, k, n, n2 = 1, find = 0, min_count = 0;

	cin >> t;
	while(t--){
		cin >> n >> k;
		vector<int> ocp(n+2, 0);
		ocp[0] = 1; ocp[n+1] = 1;

		for(int i = 0; i < k; i++){
			for(int j = 1; j < n+1; j++){
				if(ocp[j] == 0){
					pair<int, int> a = closests(ocp, j);
					minf.push_back(min(a.first, a.second));
					maxf.push_back(max(a.first, a.second));
				} else {
					minf.push_back(-1);
					maxf.push_back(-1);
				}
			}

			int l = *max_element(minf.begin(), minf.end());
			vector<int> vec;
			min_count = 0;
			for(int j = 0; j < n; j++){
				if(minf[j] == l){
				 	vec.push_back(j);
				 	min_count++;
					find = j;
				}
			}

			if(min_count > 1){
				int maior = maxf[vec[0]];
				find = vec[0];
				for(int w = 1; w < min_count; w++){
					if(maxf[vec[w]] > maior){
						find = vec[w];
						maior = maxf[vec[w]];
					}
				}
			}
			ocp[find+1] = 1;

			maxf.clear();
			minf.clear();
		}

		cout << "Case #" << n2 << ": " << maxf[find] << " " << minf[find] << endl;
		n2++;
	}

	return 0;
}