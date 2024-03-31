#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


const int N = 2*1e5;
int n;
long t[2*N];


void build(){
    for(int i = n-1; i > 0; i--) 
        t[i] = t[i<<1] ^ t[i<<1|1];
}

void modify(int p, long v){
    for(t[p+=n] = v; p > 1; p >>= 1) t[p >> 1] = t[p] ^ t[p^1]; 
}

long query(int l, int r){
   long asw = 0; 
   for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) asw ^= t[l++];
        if (r&1) asw ^= t[--r];
   }
    return asw; 
}

int main (int argc, char *argv[])
{
    int m; 
    cin >> n >> m; 
    
    for (int i = 0; i < n; i++) cin >> t[i+n];
    build(); 
    
    
    long x , y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        cout << query(x-1, y) << endl;
    }
    return 0;
}



