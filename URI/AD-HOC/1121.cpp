/*
   Nesse problema fiz da maneira q julgo a mais ineficaz e simulei literalmente
   o mapa discrito no problema. Utilizando alguns if e elses
*/
#include <bits/stdc++.h>

using namespace std;

int main(){

    int s, n, m, i ,j; // n linhas m colunas
    char map[1000][1000];
    char instr[5000000];
    int pos[2];
    int fig = 0;

    scanf("%d%d%d", &n, &m, &s);

    while (s != 0 && n != 0 && m != 0) {
        memset(map, '0', sizeof(map));
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++){
                scanf(" %c", &map[i][j]);

                if (map[i][j] == 'N' ||
                    map[i][j] == 'O' ||
                    map[i][j] == 'S' ||
                    map[i][j] == 'L'  ) {

                    pos[0] = i;
                    pos[1] = j;
                }
            }
        }

        for (int i = 0; i < s; i++) {
            scanf(" %c", &instr[i]);
        }

        for (int i = 0; i < s; i++) {
            if (instr[i] == 'D') {
                if (map[pos[0]][pos[1]] == 'N')
                    map[pos[0]][pos[1]] = 'L';

                else if (map[pos[0]][pos[1]] == 'S')
                    map[pos[0]][pos[1]] = 'O';

                else if (map[pos[0]][pos[1]] == 'L')
                    map[pos[0]][pos[1]] = 'S';

                else if (map[pos[0]][pos[1]] == 'O')
                    map[pos[0]][pos[1]] = 'N';
            }

            if (instr[i] == 'E') {
                if (map[pos[0]][pos[1]] == 'N')
                    map[pos[0]][pos[1]] = 'O';

                else if (map[pos[0]][pos[1]] == 'S')
                    map[pos[0]][pos[1]] = 'L';

                else if (map[pos[0]][pos[1]] == 'L')
                    map[pos[0]][pos[1]] = 'N';

                else if (map[pos[0]][pos[1]] == 'O')
                    map[pos[0]][pos[1]] = 'S';
            }

            if (instr[i] == 'F') {
                if (map[pos[0]][pos[1]] == 'N') {
                    if (map[pos[0]-1][pos[1]] == '*') {
                        fig++;
                        pos[0]--;
                        map[pos[0]][pos[1]] = 'N';
                        map[pos[0]+1][pos[1]] = '.';
                    } else if (map[pos[0]-1][pos[1]] == '.') {
                        pos[0]--;
                        map[pos[0]][pos[1]] = 'N';
                        map[pos[0]+1][pos[1]] = '.';
                    }
                } else if (map[pos[0]][pos[1]] == 'S') {
                    if (map[pos[0]+1][pos[1]] == '*') {
                        fig++;
                        pos[0]++;
                        map[pos[0]][pos[1]] = 'S';
                        map[pos[0]-1][pos[1]] = '.';
                    } else if (map[pos[0]+1][pos[1]] == '.') {
                        pos[0]++;
                        map[pos[0]][pos[1]] = 'S';
                        map[pos[0]-1][pos[1]] = '.';
                    }
                } else if (map[pos[0]][pos[1]] == 'L') {
                    if (map[pos[0]][pos[1]+1] == '*') {
                        fig++;
                        pos[1]++;
                        map[pos[0]][pos[1]] = 'L';
                        map[pos[0]][pos[1]-1] = '.';
                    } else if (map[pos[0]][pos[1]+1] == '.') {
                        pos[1]++;
                        map[pos[0]][pos[1]] = 'L';
                        map[pos[0]][pos[1]-1] = '.';
                    }
                } else if (map[pos[0]][pos[1]] == 'O') {
                    if (map[pos[0]][pos[1]-1] == '*') {
                        fig++;
                        pos[1]--;
                        map[pos[0]][pos[1]] = 'O';
                        map[pos[0]][pos[1]+1] = '.';
                    } else if (map[pos[0]][pos[1]-1] == '.') {
                        pos[1]--;
                        map[pos[0]][pos[1]] = 'O';
                        map[pos[0]][pos[1]+1] = '.';
                    }
                }
            }
        }
        printf("%d\n", fig);
        fig = 0;
        scanf("%d%d%d", &n, &m, &s);
    }
    return 0;
}
