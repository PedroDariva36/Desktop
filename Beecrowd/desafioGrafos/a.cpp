#include <bits/stdc++.h>
#include <queue>
#include <utility>
#define fori for (int i = 0; i < n; i++)
#define forj for (int j = 0; j < m; j++)
#define pii pair<int,int>
using namespace std;


int main (int argc, char *argv[]){

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    int n, m, a, b, colors = 0;
    cin >> n >> m;
    char g[n][m];
    bool marked[n][m];
    pii aux;
    queue<pii> q;

    fori{forj{ 
        cin >> g[i][j];
        marked[i][j] = false;
    }}

    fori{
        forj{
            if(marked[i][j] || g[i][j] == 'o') continue;
            colors++;
            q.push(make_pair(i,j));
            marked[i][j] = true;

            while (!q.empty()) {
                aux = q.front(); q.pop();
                for (int z = 0; z < 4; z++) {
                    a = aux.first + dx[z];
                    b = aux.second + dy[z];
                    if (a < 0 || a >= n || b < 0 || b >= m || marked[a][b] || g[a][b] == 'o') continue;
                    q.push(make_pair(a,b));
                    marked[a][b] = true;
                }
            }
        }
    }
    cout << colors << endl;
    return 0;
}
