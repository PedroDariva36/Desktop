#include <bits/stdc++.h>
#include <ios>
#include <queue>
#include <stack>
#define pii pair<int,int>
#define f first
#define s second

using namespace std;

char g[8][8];
bool marked[8][8];
int path[8][8];
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};
string dz[] = {"forth","right","left","down"};

// 1 2 3
// forth left right
map<char,char> d;





int main (int argc, char *argv[]){
    d['@'] = 'I';
    d['I'] = 'E';
    d['E'] = 'H';
    d['H'] = 'O';
    d['O'] = 'V';
    d['V'] = 'A';
    d['A'] = '#';

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n,m;
        cin >> n >> m;

        pii start;
        pii end = {-1,-1};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                path[i][j] = 9;
                marked[i][j] = false;
                cin >> g[i][j];
                if (g[i][j] == '@') {
                    start = {i,j};
                    path[i][j] = 8;        
                }
            }
        queue<pii> q;
        q.push(start);
        while (!q.empty()){
            pii c = q.front(); q.pop();
            if (marked[c.f][c.s]) continue;
            marked[c.f][c.s] = true;
            if (g[c.f][c.s] == '#') {
                end = c; 
                break;
            }
            for (int i = 0; i < 4; i++) {
                pii k = {c.f+dx[i],c.s+dy[i]}; 
                if (k.f > n || k.f < 0 || k.s > m || k.s < 0) continue;
                if (marked[k.f][k.s]) continue;
                if (g[k.f][k.s] != d[g[c.f][c.s]]) continue;

                path[k.f][k.s] = i;
                q.push(k);    
            }
        }
        stack<string> l;
        pii p = end; 
        while (p != start) {
            int aux = path[p.f][p.s];
            l.push(dz[aux]);
            p = {p.f-dx[aux],p.s-dy[aux]};
        } 
        
        cout << l.top(); l.pop();
        while (!l.empty()) {
            cout << " " << l.top(); l.pop();
        }
        cout << endl;

    }
    /* 
       cout << endl;
       for (int i = 0; i < n; i++){
       for (int j = 0; j < m; j++)
       cout << marked[i][j];
       cout << endl;
       } 
       cout << endl;
       for (int i = 0; i < n; i++){
       for (int j = 0; j < m; j++)
       cout << path[i][j];
       cout << endl;
       }
       */

    return 0;
}
