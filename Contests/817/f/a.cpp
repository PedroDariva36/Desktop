#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

int dx[] = {1,1,1,0,0,0,-1,-1,-1};
int dy[] = {-1,0,1,-1,0,1,-1,0,1};


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        
        char g[n][m];
        int marked[n][m]; 
        bool f = 1;
        
        ll asum = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
                marked[i][j] = 0;
                if(g[i][j] == '*') asum++;
            } 
        }
    

        int k = 1;
        //if(asum % 3 != 0) f = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                //cout << g[i][j] << " ";
                
                if(g[i][j] == '*'){
                    if(i+1 < n && i-1 >= 0 && j+1 < m && j-1 >= 0){
                        if(g[i][j] == g[i+1][j+1] && g[i][j] == g[i-1][j-1]){ 
                            f = 0;
                        }
                        if(g[i][j] == g[i+1][j-1] && g[i][j] == g[i-1][j+1]){ 
                            f = 0;
                        } 
                    }

                    if(i+1 < n && i-1 >= 0){
                        if(g[i][j] == g[i+1][j] && g[i][j] == g[i-1][j]){ 
                            f = 0;
                        }
                    }
                    if(j+1 < m && j-1 >= 0){
                        if(g[i][j] == g[i][j+1] && g[i][j] == g[i][j-1]){
                            f = 0;
                        }
                    }
                    

                    int sum = 0;
                    for (int k = 0; k < 9; k++) {
                        int it = i + dx[k]; 
                        int jt = j + dy[k]; 
                        if(it < 0 || it >= n) continue; 
                        if(jt < 0 || jt >= m) continue; 
                        if(marked[it][jt] != k && marked[it][jt] != 0){
                            f = 0;
                        } 
                        if(g[it][jt] == '*') {
                            sum++;
                            marked[it][jt] = k; 
                        }
                    }
                    k++;
                    if(sum != 3) f = 0;
                }     
            } 
        }
        cout << (f?"YES":"NO") << endl;

    }
    return 0;
}
