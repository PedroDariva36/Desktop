#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define f first
#define s second
#define pb push_back
using namespace std;


int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0,-1, 1};
int marked[1000][1000];
char g[1000][1000];
int dist[1000][1000];
int n,m, auxDist;

int main (){
    int t;
    cin >> t;    
    while(t--){
        for (int i = 0; i < 1000; i++){ 
            for (int j = 0; j < 1000; j++){
                dist[i][j] = 1e9;
                marked[i][j] = -1;
            }
        }

        stack<char> p;
        queue<pii> mq, q;
        pii start, end, current, aux;
        cin >> n >> m; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
                if (g[i][j] == 'S') start = {i,j};
                if (g[i][j] == 'E') end = {i,j}; 
                if (g[i][j] == 'F') {
                    mq.push({i,j}); 
                    dist[i][j] = 0;
                }
            }
        }

        //monster search
        while (!mq.empty()) {
            pii c = mq.front(); mq.pop(); 
            auxDist = dist[c.f][c.s] + 1;

            for (int i = 0; i < 4; i++) {
                aux = {c.f + dx[i], c.s + dy[i]};
                if (aux.f < 0 || aux.f >= n || aux.s < 0 || aux.s >= m) continue;
                if (dist[aux.f][aux.s] <= auxDist) continue;
                if (g[aux.f][aux.s] == '#') continue;

                dist[aux.f][aux.s] = auxDist; 
                mq.push(aux);
            }
        }

        q.push(start);
        marked[start.f][start.s] = 0;
        while (!q.empty()) {
            pii c = q.front(); q.pop();

            auxDist = marked[c.f][c.s] + 1;
            for (int i = 0; i < 4; i++) {
                aux = {c.f + dx[i], c.s + dy[i]};
                if (aux.f < 0 || aux.f >= n || aux.s < 0 || aux.s >= m) continue;
                if (dist[aux.f][aux.s] <= auxDist || marked[aux.f][aux.s] != -1) continue;
                if (g[aux.f][aux.s] == '#') continue;

                marked[aux.f][aux.s] = auxDist; 
                q.push(aux);
            }
        }

        cout << ((marked[end.f][end.s] != -1)?"Y":"N") << endl;
    } 
    return 0;
}
