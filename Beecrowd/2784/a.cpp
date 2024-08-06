#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


const ll INF = 1e9;
ll dist[1001];    
bool marked[1001];



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    ll a, b, c, k; 


    vector<pll> g[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        marked[i] = false;
    } 


    for (int i = 0; i < m; i++ ) {
        cin >> a >> b >> c;
        g[a-1].push_back({b-1,c});
        g[b-1].push_back({a-1,c}); 
    }        
    cin >> k;     
    k--;        

    priority_queue<pll> q;
    dist[k] = 0;
    q.push({0,k}); 

    while (!q.empty()) {
        ll x = q.top().second; q.pop();
        if(marked[x]) continue;
        marked[x] = true; 
        
        for (auto i: g[x]) {
            ll y = i.first, w = i.second; 
            if (dist[x]+w < dist[y]) {
                dist[y] = dist[x]+w;
                q.push({-dist[y],y});
            }            
        }

    }  
    ll mx = 0;
    ll mn = INF;
    for (int i = 0; i < n; i++) {
        if(i == k) continue; 
        mx = max(mx, dist[i]); 
        mn = min(mn, dist[i]); 
        //cout << i << " " << dist[i] << endl;
    } 

    cout << abs(mx - mn) << endl;


    return 0;
}
