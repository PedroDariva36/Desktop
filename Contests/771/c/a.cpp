#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

const int N = 1e5;
int parent[N];
int rk[N];

void make_set(int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

bool same_set(int a, int b){
    return (find_set(a) == find_set(b));
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (rk[a] < rk[b]) swap(a,b);
        parent[b] = a;
        if (rk[a] == rk[b]) rk[b]++;
    }
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            make_set(i);
        }
        
        set<int> b;
        b.insert(a[0]);
        int c = n; 
        for (int i = 1; i < n; i++) {
            auto it = b.upper_bound(a[i]);
            if (it == b.end()) {
                b.insert(a[i]); 
            } 
            else {
                for (; it != b.end(); it++) {
                    union_sets(*(it),i);
                }
            }
        }

        

        /*
        for (auto i: b) {
            cout << i << endl; 
        }
        */
        //cout << c << endl;
    }
    return 0;
}
