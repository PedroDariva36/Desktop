#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

const int N = 2*10e5+1;
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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            make_set(i);
        }

        vector<pair<int,int>> a(n); 
        for(auto &i: a) cin >> i.first >> i.second;
        
        
        for(auto &i: a){
            i.first--;
            i.second--;
            if(find_set(i.first) == find_set(i.second)) continue;
            union_sets(i.first, i.second);
        } 
        bool f= 1; 
        for (int i = 0; i < n; i++) {
            if(sz[i]%2 == 1){
                f = 0;
                break;
            }
        }

        cout << (f? "YES":"NO") << endl;






         

    }
    return 0;
}
