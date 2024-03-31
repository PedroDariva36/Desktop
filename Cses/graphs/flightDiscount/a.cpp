#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <vector>
#define pil pair<int,long>
using namespace std;


int main (int argc, char *argv[]){
    long c;
    int n, m, a, b;
    
    cin >> n >> m;
    long dist[n];
    bool marked[n];
    vector<pil> g[n];
    while (m--) {
        cin >> a >> b >> c;
        g[a-1].push_back({b-1,c});
    }
    long old = 0;
    long minimum = LONG_MAX-1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < g[i].size(); j++){
            old =  g[i][j].second;
            g[i][j].second = g[i][j].second/2;

            priority_queue<pair<long,int>> q;
            for (int z = 0; z < n; z++){
                dist[z] = LONG_MAX;
                marked[z] = false;
            }

            dist[0] = 0;
            q.push({0,0});
            while (!q.empty()) {

                int x = q.top().second; q.pop();
                if (marked[x]) continue;
                marked[x] = true;

                for (auto j : g[x]) {
                    int y = j.first, z = j.second;
                    if (dist[x]+z < dist[y]) {
                        dist[y] = dist[x]+z;
                        q.push({-dist[y],y});
                    }
                } 
            }
            g[i][j].second = old; 
            minimum = min(minimum, dist[n-1]);
        }
    }
    
    cout << minimum << endl;

    return 0;
}
