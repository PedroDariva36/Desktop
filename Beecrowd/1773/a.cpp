#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <vector>
 
using namespace std;
 
const int N = 1+1e3;
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
    while(cin >> n >> m){
        for (int i = 0; i < n; i++) make_set(i); 

        vector<pair<int,int>> s;
        while (m--) {
            cin >> a >> b; 
            a--;b--;
            s.push_back({a,b}); 
        }
        
        
        vector<int> p(s.size());
        for (auto &i: p) {
            cin >> i;
            i--;
        }
        int kq = 1; 
                

          
    }
    return 0;
}
