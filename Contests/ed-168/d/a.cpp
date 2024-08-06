#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

ll dfs(int x, vector<vector<int>> &g, vector<ll> &a){
    if(g[x].size() == 0) return a[x];
       
    ll k = 1e12;
    for (auto i : g[x]) {
        k = min(dfs(i,g,a),k);
    }
    
    
    if(a[x] >= k) return k;

    ll l = abs(a[x] + k)/2;
    return l;

}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int aux;
        vector<vector<int>> g(n);
        vector<ll> a(n);
        for (auto &i : a) cin >> i;
        for (int i = 0; i < n-1;i++) {
            cin >> aux;
            g[aux-1].pb(i+1);
        } 
        ll k = 1e12; 
        for (auto i: g[0]) {
           k = min(k,dfs(i,g,a));
        }
        cout << k + a[0] << endl;;





        
         

    }
    return 0;
}
