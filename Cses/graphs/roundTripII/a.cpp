#include <bits/stdc++.h>
#include <cstdint>
#include <vector>
#define N 1000005

using namespace std;


bool marked[N];
bool visited[N];
vector<int> g[N]; 
int father[N];

//int seed = -1;


int dfs(int x) {
    if (visited[x]) return -1;
    if (marked[x]) {
        return x;
    }
    marked[x] = true;
    
    int mx = -1;
    
    for (auto u: g[x]) {
        mx = max(mx,dfs(u));
        father[u] = x;
    }

    visited[x] = true;
    return mx;
}


int main (int argc, char *argv[]){
    
    int n,m,a,b;
    cin >> n >> m;
    
    for (int i = 0; i <= n; i++) {
        father[i] = -1;
        visited[i] = false;
        marked[i] = false;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b; 
        g[a].push_back(b);
    }

    cout << "GOOOO"<< endl;    
    int l = dfs(1);
    cout << "GGGGGG" << endl;
    if(l == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> steps;
    steps.push_back(l);
    int aux = father[l];
    
    for(int i = 0 ; i <= n; i++) 
        cout << father[i] << " ";
    cout << endl;


    while (aux != l) {
        steps.push_back(aux);
        aux = father[aux];
        //cout << aux << endl;
    }
    steps.push_back(aux);


    
    cout << steps.size() << endl;
    for(auto &i: steps) 
        cout << i << " ";
    cout << endl;
    

    return 0;
}
