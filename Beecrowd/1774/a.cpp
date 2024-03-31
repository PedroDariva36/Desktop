#include <bits/stdc++.h>
#include <iterator>
#include <queue>
#include <vector>
#define pii pair<int,int>
#define pip pair<int, pii>
using namespace std;

int n, m, a, b, c, vcounter = 0;
long long counter = 0;


int main (int argc, char *argv[]){
    cin >> n >> m;
    vector<pii> g[n+1];
    priority_queue<pip> q;
    bool marked[n+1];
    
    for (int i = 0; i <= n; i++) marked[i] = false;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    
    for (auto i : g[1]) q.push({-i.second, {i.first, 1}});
    
    while (!q.empty()) {
        c = -q.top().first;
        a = q.top().second.first;
        b = q.top().second.second;
        q.pop();
        
        if (marked[a] && marked[b]) continue;

        marked[a] = true;
        marked[b] = true;
        counter += c;
        
        for (auto i : g[a]) q.push({-i.second, {i.first, a}});
        
    }
        
    cout << counter << endl;
    
    return 0;
}
