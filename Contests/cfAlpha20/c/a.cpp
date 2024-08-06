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
    int n,m;
    cin >> n >> m;
     
    ll dist[n+1];
    bool marked[n+1];
    ll father[n+1];
    vector<pair<ll, ll>> g[n+1];
    priority_queue<pair<ll,ll>> q;
 
 
 
    for (int i = 0; i < n+1; i++) {
        dist[i] = 2e16;
        marked[i] = false;
        father[i] = -1;
    }
 
    ll a,b;
    ll c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c; 
        g[a].push_back({b,c});
        g[b].push_back({a,c}); 
    }
    
   
    dist[1] = 0;
    for (int i = 2; i < n+1 ; i++) {
        q.push({-dist[i],i});
    }
    
    q.push({0,1});

    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (marked[a]) continue;
        marked[a] = true;
        for (auto u : g[a]) {
            ll b = u.first, w = u.second;
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                father[b] = a;
                q.push({-dist[b],b});
            }
        }
    }
    
    vector<int> path;
    int k = n; 
    while (k != -1) {
        path.push_back(k); 
        k = father[k];
    }
    if (path.size() != 0 && path.back() == 1) {
        reverse(path.begin(),path.end()); 
        for(auto i: path){
            cout << i << " ";
        } 
        cout << endl;
    }
    else cout << -1 << endl;
 
    return 0;
}
 
