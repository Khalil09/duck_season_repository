#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>

bool sort_by_lucro(ii a, ii b){ return a.first > b.first; }

int main(){
	int n, h, v, t, lost = 0, hour = 0;
	vector<ii> l;

	while(scanf("%d %d", &n, &h) == 2){
		int n2 = n;
		vector<bool> p(h, 0);
		while(n--){
			cin >> v >> t; 
			l.push_back(make_pair(v, t));
			
		}

		sort(l.begin(), l.end(), sort_by_lucro);
		int j = 0;
		int marked = false;
		for(int i = 0; i < n2; i++){
			j = 0;
			marked = false;
			while((l[i].second-1) - j >= 0 && !marked){
				if(!p[(l[i].second-1) - j]){
					p[(l[i].second-1) - j] = true;
					l[i].first = 0;
					marked = true;
				} else j++;
			}
		}

		
		for(auto g : l){
			lost += g.first;
		}

		cout << lost << endl;
		
		lost = 0;

		p.clear();
		l.clear();
	}

	return 0;	
}