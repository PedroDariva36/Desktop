#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2*1e6+1;
int n;
ll t[N+N];

void build(){
    for(int i = n-1; i > 0; i--) 
        t[i] = max(t[i<<1], t[i<<1|1]);
}

void update(int p, ll v){
    for(t[p] = v; p > 1; p >>= 1)
        t[p>>1] = max(t[p], t[p^1]);
}

int query(ll v){
    int p = 1;
    while (p < n) {
        if(t[p<<1] >= v) 
            p = p<<1;         
        else 
            p = (p<<1) + 1; 
    }

    return p;
}



int main (int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s;
    int m, p;
    ll k;
    cin >> s >> m;
    
    n = 1;
    while (n < s) n <<= 1;
    for (int i = n; i < n+s;i++) cin >> t[i];
    
    build();
    
    for (int i = 0; i < m; i++) {
        cin >> k;
        p = query(k);
        
        if(t[p] < k) cout << 0 << " ";
        else { 
            update(p, t[p]-k);
            cout << p-n+1 << " " ;

        }
    }
    cout << endl;

    return 0;
}
