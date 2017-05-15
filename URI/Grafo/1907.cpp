#include <bits/stdc++.h>

using namespace std;

char pi[1025][1025];
int n, m, ct = 0;

void dfs(int i, int j){
	pi[i][j] = 'o';
	if(i + 1 < n && pi[i+1][j] == '.') dfs(i+1, j);
	if(i - 1 >= 0 && pi[i-1][j] == '.') dfs(i-1, j);
	if(j + 1 < m && pi[i][j+1] == '.') dfs(i, j+1);
	if(j - 1 >= 0 && pi[i][j-1] == '.') dfs(i, j-1);
}

int main(){

	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> pi[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(pi[i][j] == '.'){
				dfs(i, j);
				ct++;
			}
		}
	}

	cout << ct << endl;

	return 0;
}