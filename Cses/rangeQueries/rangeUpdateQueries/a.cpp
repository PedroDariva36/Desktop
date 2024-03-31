#include <bits/stdc++.h>

using namespace std;

const int N = 2*1e5;
long t[2*N];
int n;

void build(){
    for (int i = 0; i< n*2; i++) t[i] = 0;
}

void rangeUpdate(int l, int r, long value){
    for(l += n, r += n; l < r; l >>= 1, r >>=1){
        if (l&1) t[l++] += value;
        if (r&1) t[--r] += value;
    } 
}


long rangeQuerie(int p){
    long asw = 0;
    for( p += n; p > 0; p >>= 1) asw += t[p];
    return asw;
}





int main (int argc, char *argv[]){
    int m; 
    cin >> n >> m;
    
    build();  
    for(int i = 0; i < n; i++)
        cin >> t[i+n];
    
   
    
    int op, x, y;
    long z;
    for(int i = 0; i < m; i++){
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> z;
            rangeUpdate(x-1,y,z);
        }
        else{
            cin >> x;
            cout << rangeQuerie(x-1) << endl;
        }
    }

    return 0;
}
