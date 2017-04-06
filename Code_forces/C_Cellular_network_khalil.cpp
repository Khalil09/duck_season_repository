#include <bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
#define D(a) cout << "DEBUG:" << a << endl

bool sort_pair(ii a, ii b){return  a.second > b.second;}

int main(){
	long long int n, m, aux, r, maior = 0;
	vector<ii> cid;
	vector<int> tor;

	cin >> n >> m;

	while(n--){
		cin >> aux;
		cid.push_back(ii(aux, 3));
	}
	while(m--){
		cin >> aux;
		tor.push_back(aux);
	}

	for(int i = 0; i < cid.size(); i++){
		maior = abs(cid[i].first - tor[0]);
		for(auto t : tor){
			cid[i].second = maior;
			if(abs(cid[i].first - t) < maior){
				cid[i].second = abs(cid[i].first - t);
				maior = abs(cid[i].first - t);
			}
		}
	}
	sort(cid.begin(), cid.end(), sort_pair);

	cout << cid.begin()->second << endl;
	
	return 0;
}