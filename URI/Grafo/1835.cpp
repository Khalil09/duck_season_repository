#include <bits/stdc++.h>

using namespace std;

#define D(a) cout << "Debug: " << a << endl;

int n, m;
vector< vector<int> > grafo;
int visitados[200];
int cont;

void dfs(int u){
	visitados[u] = 1;

	for(int j = 0; j < (int)grafo[u].size(); j++){
		int v = grafo[u][j];
		if(visitados[v] == -1){
			dfs(v);
		}
	}
}

int main(){
	int t, n2;

	cin >> t;
	n2 = 1;

	while(t--){
		cin >> n >> m;

		grafo.assign(n+1, vector<int>());

		for(int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a); 
		}

		memset(visitados, -1, sizeof(visitados));

		dfs(1);
		for(int i = 1; i <= n; i++){
			if(visitados[i] == -1){
				dfs(i);
				cont++;
			}
		}

		if(cont == 0){
			cout << "Caso #" << n2 << ": " << "a promessa foi cumprida" << endl;
		} else {
			cout << "Caso #" << n2 << ": " << "ainda falta(m) " << cont << " estrada(s)" << endl;
		}
		n2++;
		cont = 0;
		grafo.clear();
	}
	return 0;
}