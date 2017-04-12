#include <bits/stdc++.h>

using namespace std;

int make_nine(string *s, int k){
	for(int i = k; i < (*s).length(); i++){
		(*s)[i] = '9';
	}	
}

int main(){
	int n, n2 = 1, i;
	string p;

	cin >> n;
	while(n--){
		// getchar();
		getline(cin >> ws, p);

		for(i = p.length()-1; i >= 1; i--){
			if((int)p[i] < (int)p[i-1]){
				make_nine(&p, i);
				(int)p[i-1]--;
			}
		}
		if(p[0] == '0') p.erase(0, 1);
		
		cout << "Case #" << n2 << ": " << p << endl;
		n2++;
		p.clear();
	}

	return 0;
}