#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n,m;
        cin >> n >> m;
        ll g[n][m];

        for (int i= 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
            }
        }
        
        for (int i= 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ll mx = -1;
                if(i+1 < n) mx = max(mx,g[i+1][j]); 
                if(i-1 >= 0) mx = max(mx,g[i-1][j]);
                if(j+1 < m) mx = max(mx,g[i][j+1]); 
                if(j-1 >= 0) mx = max(mx,g[i][j-1]);
                if(mx < g[i][j]) g[i][j] = mx;
            }
        }
        
     for (int i= 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << g[i][j] << " ";
            }
            cout << endl;;
        }
    }
    return 0;
}
