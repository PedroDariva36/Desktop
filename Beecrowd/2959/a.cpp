#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

const long N = 1e4+1;
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

bool same_set(int a, int b){
    return (find_set(a) == find_set(b)); 
}


void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap(a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            rk[a]++;
    }
}


int main (int argc, char *argv[]){
    //cin.tie(0)->sync_with_stdio(0);
    int n,m,q;
    int a,b;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) make_set(i); 

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        union_set(a-1,b-1);
    }
    while (q--) {
        cin >> a >> b;
        cout << ((same_set(a-1, b-1))? "Lets que lets":"Deu ruim") << endl;
    }        



    return 0;
}
