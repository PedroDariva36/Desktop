#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
#include <ios>
#include <iterator>
#include <limits>
#include <utility>
#include <vector>
#define ll long long 
#define pli pair<ll , int>
using namespace std;
 
 
int n,m,a,b,c;
ll x;

int main (int argc, char *argv[]){
    
    cin >> n >> m; 
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll dist[n+1];
    bool marked[n+1];
    vector<pair<int, long>> g[n+1];
    priority_queue<pli> q;



    for (int i = 0; i < n+1; i++) {
        dist[i] = LLONG_MAX;
        marked[i] = false;
    }

    
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c; 
        g[a].push_back({b,c});
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
                q.push({-dist[b],b});
            }
        }
    }


    for (int i = 1; i < n+1; i++) {
        cout << dist[i] << endl;
    }

    return 0;
}
