#include <algorithm>
#include <bits/stdc++.h>
#include <ios>

using namespace std;

const int N = 2*1e5;
int parent[N];
int sz[N];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main (int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    int n, m;
    int a, b;
    cin >> n >> m;
        
    for (int i = 0; i < n; i++) {
        make_set(i); 
    }



    int x = 1;
    int c = n;
    for (int i = 0; i < m; i++) {
        cin >> a >> b; 
        a--;b--;
        if (find_set(a) != find_set(b)) {
            union_sets(a, b);
            c--;
            x = max(x, sz[parent[a]]);
            x = max(x, sz[parent[b]]);
        }
        cout << c << " " << x << endl;
    }

return 0;
}
