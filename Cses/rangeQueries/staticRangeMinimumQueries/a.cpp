#include <bits/stdc++.h> 

using namespace std;


const long N = 2*1e5;
int n;
long t[2 * N];

void build() {
    for (int i = n - 1; i > 0; --i)
        t[i] = min(t[i<<1] , t[i<<1|1]);
}

void modify(int p, int value) { 
    for (t[p += n] = value; p > 1; p >>= 1) 
        t[p>>1] = min(t[p], t[p^1]);
}


long query(int l, int r) {
    long res = 10e9+1 ;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(t[l++],res);
        if (r&1) res = min(t[--r], res);
    }
    return res;
}


int main (int argc, char *argv[]){
    
    int m,x,y;
    vector<long> a;


    cin >> n >> m;
    
    build();
     
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        cout << query(x-1, y-1) << endl; 
    }

    
    
    return 0;
}
