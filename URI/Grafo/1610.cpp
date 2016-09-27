/* Problema pode ser resolvido facilmente com uma personalizacao do DFS
   identificando se existe um loop ou n atravez do sistema de cores branco,
   cinza e preto */

#include <bits/stdc++.h>

#define BRANCO 0
#define CINZA 1
#define PRETO 2

using namespace std;

vector<vector<int> > grafo;
bool loop;
int color[10004];

void dfs (int u) {
    if (color[u] == BRANCO) {
    /* Se o vetor for um vertice ainda nao visitado(BRANCO) */
        color[u] = CINZA;
        /* Torna-lo cinza para marcar que estamos
         no segmento que o vertice pertence

            B <- Será o proximo a se tornar cinza
            |
            C <- Ja visitado torna-se cinza
             \
             C <- Ja visitado torna-se cinza(inicio do grafo)
        */

        for (int i = 0; i < grafo[u].size(); i++) {
            int v = grafo[u][i];
            /* Grava em v o proximo adjacente do vertice u */
            dfs(v);
            /* Chama recursivamente o dfs para o vertice v */
        }

    } else if (color[u] == CINZA) {
    /* Caso ele passe por um vertice que já eh cinza significa
     que existe um loop nesse grafo

         C <- Outro cinza encontrado
        | \
        |  \
        C--C
    */
        loop = true;
    }
    color[u] = PRETO;
    /* Colore de preto aquele vertice do qual
     esta retornando do caminho do grafo */
}

int main(){
    int t, n, m, a, b;

    scanf("%d", &t);

    while(t--){
        scanf("%d%d", &n, &m); /* Numero de vertices e arestas */
        grafo.assign(n+1, vector<int>());
        /* Aloca um vetor de int de tamanho n */

        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b); /* Documento A depende de B */
            grafo[a].push_back(b);
            /* B filho de A, entao entra na lista de adjacencentes*/
        }

        loop = false;
        memset(color, BRANCO, sizeof(color));
        /* Torna todos os vertices como nao visitados(BRANCO) */
        for (int j = 1; j <= n; j++) {
        /* Este for garante que passaremos por todos os vertices, incluse
        aqueles que nao possuem conexao com nenhum outro vertice */
            dfs(j);
            /* Fazer um dfs personalizado no grafo
            proposto para descobrir loops.*/
        }
        printf("%s\n", loop ? "SIM" : "NAO");

    }

    return 0;
}
