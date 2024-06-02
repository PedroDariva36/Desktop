#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int dx[] = {-1,-1, 1, 1, 0, 0,-1, 1};
int dy[] = {-1, 1,-1, 1,-1, 1, 0, 0};


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
        int n,m;
        int a, b;
        cin >> n >> m;
        cin >> a >> b;
        char g[n][m];
        int c[n][m];
    
        a--;
        b--;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
                c[i][j] = 0;
            } 
        }
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '.') {
                    
                    for (int k = 0; k < 4; k++) {
                        int x = i + a*dx[k];
                        int y = j + b*dy[k];
                        if (x < 0 || x >= n) continue;
                        if (y < 0 || y >= m) continue;
                        if(g[x][y] == '*') c[i][j]++;
                    }
                    
                    for (int k = 0; k < 4; k++) {
                        int x = i + b*dx[k];
                        int y = j + a*dy[k];
                        if (x < 0 || x >= n) continue;
                        if (y < 0 || y >= m) continue;
                        if(g[x][y] == '*') c[i][j]++;
                    }



                }
            } 
        }
        
        int max = -1;
        pair<int,int> pos;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //cout << c[i][j]; 
                
                if (c[i][j] > max && g[i][j] == '.') {
                    pos = {i,j};
                    max = c[i][j];
                }
                
            } 
            //cout << endl;
        } 
       
        cout << pos.first+1 << " " << pos.second+1 << endl;



    return 0;
}
