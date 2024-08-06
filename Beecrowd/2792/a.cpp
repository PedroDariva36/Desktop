#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;
 
const int N = 2*1e6+1;
int n;
int t[N+N] = {0};
vector<ll> a;
 
void build(){
    for(int i = n-1; i > 0; i--) 
        t[i] = t[i<<1] + t[i<<1|1];
}

void update(int p, int v){
    for(t[p] = v; p > 1; p >>= 1)
        t[p>>1] = t[p] + t[p^1];
}

long query(int l, int r){
   long asw = 0; 
   for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) asw += t[l++];
        if (r&1) asw += t[--r];
   }
    return asw; 
}
 
int main (int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s;
    ll aux;
    cin >> s;
    
    n = 1;
    while (n < s) n <<= 1;
    for (int i = 0; i < s; i++) t[n+i] = 1;
    
    vector<int> a(s);
    for (auto &i : a) cin >> i; 
    build();
    
    cout << query(0, a[0]);
    update(n+a[0]-1, 0);
    for (int i = 1; i < s; i++) {
        cout  << " "<< query(0, a[i]);
        update(n+a[i]-1, 0);
    }

    //cout << endl;
    return 0;
}
