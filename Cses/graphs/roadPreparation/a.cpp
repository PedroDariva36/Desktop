#include <algorithm>
#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;


const int N = 2*1e5;
int parent[N];
int rk[N];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    rk[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rk[a] < rk[b]) swap(a, b);
        parent[b] = a;
        if (rk[a] == rk[b]) rk[a]++;
    }
}

int main (int argc, char *argv[]){
    
    int n, m;
    int a, b;
    long c;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        make_set(i);
    }

    vector<tuple<long,int,int>> e;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--;b--;
        e.push_back({c,b,a});
    }
    long long sum = 0; 
    sort(e.begin(),e.end());
    int k = n; 
    for (auto &i : e) {
        tie(c,a,b) = i; 
        if (find_set(a) != find_set(b)) {
            union_sets(a, b);
            sum += c;
            k--;
        }
    }

    if (k == 1) cout << sum << endl;
    else cout << "IMPOSSIBLE" << endl;
        


    return 0;
}
