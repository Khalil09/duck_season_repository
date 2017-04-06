#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, l, r, a, truth = 0;
	bool change = false;
	vector<int> v;
	vector<int> f;

	cin >> n >> l >> r;

	int i = n;
	while(i--){
		cin >> a;
		v.push_back(a);
	}
	i = n;
	while(i--){
		cin >> a;
		f.push_back(a);
	}

 
	if(change) cout << "LIE" << endl;
	else cout << "TRUTH" << endl;

	return 0;
}