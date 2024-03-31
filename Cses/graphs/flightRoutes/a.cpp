#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <vector>
#define ll long long
#define pil pair<int,long>
#define pli pair<long,int>
const int N = 1e5;


using namespace std;

priority_queue<ll> dist[N];
vector<pil> g[N];

int main (int argc, char *argv[]){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int a, b;
    long k, c;
    cin >> n >> m >> k; 

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        g[a-1].push_back({b-1,c});
    }
     

    //priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    
    priority_queue<pli> q;
    
    dist[0].push(0);
    q.push({0,0});
    


    while (!q.empty()) {
            
        long w = -q.top().first;
        int c = q.top().second;
        q.pop();
        
        if (dist[c].top() < w) continue;
            
        for (auto i : g[c]) {
            if (dist[i.first].size() < k) {
                dist[i.first].push({i.second + w});
                q.push({-(i.second + w), i.first});
                continue;
            }

            if (w + i.second < dist[i.first].top()) {
                dist[i.first].pop();
                dist[i.first].push(w + i.second);
                q.push({-(w + i.second),i.first});
            }
        }
    }
    vector<ll> aux;
    while (!dist[n-1].empty()) {
        aux.push_back(dist[n-1].top());
        dist[n-1].pop();
    }
    for (int i = aux.size()-1; i >= 0; i--) cout << aux[i] <<" ";    
    cout << endl;

    return 0;
}

