#include <bits/stdc++.h>
#include <exception>
#include <queue>
#include <vector>


using namespace std;

vector<list<int>> g;

bool busca_larg(int v, vector<bool> &marcado, vector<int> &dist) {
    
    queue<int> fila;
    marcado[v] = 1;
    dist[v] = 0;

    fila.push(v);
    while (!fila.empty()) {

        int w = fila.front(); fila.pop();
        for (auto u : g[w]){
            if (marcado[u] == 0) {
                marcado[u] = 1;
                dist[u] = dist[w] + 1;
                fila.push(u);
            }
            else if ((dist[w] % 2) == (dist[u] % 2)) return false;
        }
    }
    return true;
}




int main (int argc, char *argv[]){
    int n, m, a, b, aux;
    cin >> n >> m;
    
    vector<int> dist(n);
    vector<bool> marcado(n);
    g.resize(n);
    

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    for (int i = 0; i < n; i++) 
        if (!marcado[i]){ 
            if(!busca_larg(i,marcado, dist)){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
        
    for (int i = 0; i < n; i++) 
        cout << 1 + (dist[i]%2) << " "; 
    cout << '\n';
    return 0;
}
