#include <bits/stdc++.h>

using namespace std;

int pizzas(const vector<int>& p, const vector<int>& u, int n, int m){
	if(n == 0 || m == 0){ 
		return 0;
	} else {
		if(p[n-1] > m){
			return pizzas(p, u, n-1, m);
		} else {
			return max(u[n-1] + pizzas(p, u, n-1, m-p[n-1]), pizzas(p, u, n-1, m));
		}	
	}
}

vector<int> p
int main(){
	
	cin >> n;

	while(n != 0){
		cin >> m;

		for(int i = 0; i < n; i++){
			int a, b;
			cin >> a >> b;
			u.push_back(a);
			p.push_back(b);
		}

		cout << f(0, 0) << " min." << endl;
		p.clear();
		u.clear();
		cin >> n;
	}
}