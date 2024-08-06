#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


void dfs(int v, vector<vector<int>> &g, vector<bool> &m, vector<ll> &s) {
    m[v] = true;
    bool f = 0;
    ll sum = 0; 
    for (int u : g[v]) {
        if (!m[u]){
            f = 1; 
            dfs(u,g,m,s);
            sum += s[u];
        }
    }
    s[v] = sum;
    if(f == 0) s[v] = 1;
}

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        vector<bool> marked(n,0);
        vector<ll> s(n);
         int x , y;   
        for (int i = 0; i < n-1; i++) {
            cin >> x >> y;
            g[x-1].pb(y-1);
            g[y-1].pb(x-1);
        }
        dfs(0,g,marked,s); 
        
        int q;
        cin >> q; 
        while(q--){
            cin >> x >> y;
            x--; y--;
            cout << s[x] * s[y] << endl;
        } 

            


    }
    return 0;
}
