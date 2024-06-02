#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <tuple>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

const int N = 1001;
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
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    int a,b,c;
    while (cin >> n >> m) {
        
        for (int i = 0; i < n ; i++) make_set(i); 
       
        priority_queue<tuple<int,int,int>> q;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            q.push({-c,a-1,b-1});
        }
        int k = n;
        ll sum = 0; 
        while (!q.empty()) {
            tie(c, a, b) = q.top(); q.pop();
            c = -c;
            if (find_set(a) == find_set(b)) continue;            
            k--; 
            sum += c;
            union_sets(a,b);
        }
       
        
        if (k == 1) cout << sum << endl; 
        else cout << "impossivel" << endl;        

    }

    return 0;
}
