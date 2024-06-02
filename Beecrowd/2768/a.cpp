#include <bits/stdc++.h>
    
int g[100][100];
int o[101][101];
int kek[100][100][100];

int n, m, q;
int a, b, c;
const int INF = 2*1e3+1;



using namespace std;

int main (int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);  

    while(cin >> n >> m){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) g[i][j] = 0;    
                else g[i][j] = INF;
            }
        }

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c; 
            a--;
            b--;
            g[a][b] = c; 
            g[b][a] = c;

        }


        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    kek[k][i][j] = g[i][j];
                }
            }
        }


        cin >> q; 
        for (int i = 0; i < q; i++) {
            cin >> a >> b >> c;
            a--;
            b--;
            c--;
            if(kek[c][a][b] == INF){
                cout << -1 << endl;
            }
            else {
                cout << kek[c][a][b] << endl;
            }
        }
    }
    return 0;
}
