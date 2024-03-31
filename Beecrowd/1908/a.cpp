#include <bits/stdc++.h>
#include <ios>
#include <vector>

using namespace std;


vector<list<int>> g;

void busca_larg(int v, vector<int> &dist, int n, int c) {
    vector<bool> marcado(n);
    // Criacao e inicializacao do vetor marcado
    // Inicializacao do vetor dist
    queue<int> fila;
    marcado[v] = 1;
    dist[v] = 0;

    fila.push(v);
    while (!fila.empty()) {

        int w = fila.front(); fila.pop();
        for (auto u : g[w])
            if (marcado[u] == 0) {
                marcado[u] = 1;
                dist[u] = dist[w] + 1;
                if (u == c-1) return;
                fila.push(u);
            }
        
    }
}


int main (int argc, char *argv[]){
    int c, l , aux, n, x;
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> c >> l;
    n = c+l;
    g.resize(n);
    vector<int> dist(n);
    

    for ( int k = 0; k < l; k++) {
        cin >> aux;
        for (int i = 0; i < aux; i++) {
            cin >> x;
            g[x-1].push_back(c+k);
            g[c+k].push_back(x-1);
        }
    }
    /*
    int v = 0;
    for (auto &i  : g) {
        cout << v++ <<": "; 
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    */
    
    busca_larg(0, dist, n, c);
    cout << dist[c-1]/2 << endl;

    return 0;
}
