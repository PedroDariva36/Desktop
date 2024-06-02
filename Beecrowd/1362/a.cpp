#include <bits/stdc++.h>
#include <map>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;


vector<vector<int>> capacity;
vector<vector<int>> adj;

int INF = 1e9;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t, int n) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    map<string, int> c;
    c["XS"] = 1;
    c["S"] = 2;
    c["M"] = 3;
    c["L"] = 4;
    c["XL"] = 5;
    c["XXL"] = 6;

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string a, b;
        cin >> n >> m;
        int k = n/6;         
        
        adj.clear();
        capacity.clear();


        adj.resize(8+m);
        capacity.resize(8+m);
        for (auto &i : capacity) i.resize(8+m,0); 
         
        for (int i = 1; i <= 6; i++) {
            adj[0].push_back(i);
            adj[i].push_back(0);
            
            capacity[0][i] = k;
            capacity[i][0] = k;
        }
        int z = 7+m;
        for (int l = 7; l < m+7; l++) {
//            cout << l << endl;

            cin >> a >> b;
            int x = c[a], y = c[b];
//            cout << x << " " << y << endl; 


            adj[x].push_back(l);
            adj[l].push_back(x);
            capacity[x][l] = 1;
            capacity[l][x] = 1; 

            adj[y].push_back(l);
            adj[l].push_back(y);
            capacity[y][l] = 1;
            capacity[l][y] = 1;

            adj[z].push_back(l);
            adj[l].push_back(z);
            capacity[z][l] = 1;
            capacity[l][z] = 1; 

        }
        //cout << maxflow(0, z, z+1) << endl;
        cout << (maxflow(0, z, z+1) >= m? "YES": "NO") << endl;

    }

    return 0;
}
