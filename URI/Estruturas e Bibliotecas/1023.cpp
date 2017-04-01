#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>

#define D(a) cout << "Debug: " << a << endl;

int main(){
	int n, consumo, qtd_mor, insert, n2 = 1, r = 0;
	double ans_mor = 0, ans_con = 0;
	map<int, int> m;

	cin >> n;

	while(n != 0){
		if(r != 0)
			cout << endl;
		r = 1;
		cout << endl;
		while(n--){
			cin >> qtd_mor >> consumo;
			ans_con += consumo;
			ans_mor += qtd_mor;
			insert = floor(consumo/qtd_mor);

			if(m.find(insert) == m.end()){
				m.insert(ii(insert, qtd_mor));
			} else {
				auto v = m.find(insert);
				v->second += qtd_mor; 
			}
		}

		cout << "Cidade# " << n2 << ":" << endl;

		for(auto g : m){	
			cout << g.second << "-" << g.first;
			m.erase(g.first);
			if(!m.empty()){
				cout << " ";
			}
		}
		cout << endl;

		double l = (ans_con/ans_mor);

		double dec = l - (int)l;
		dec *= 100;
		dec = (int)dec;
		dec /= 100;

		double final = (int)l + dec;

		printf("Consumo medio: %.2lf m3.", final);
		m.clear();
		ans_mor = 0;
		ans_con = 0;
		cin >> n;
		n2++;
	}

	return 0;
}