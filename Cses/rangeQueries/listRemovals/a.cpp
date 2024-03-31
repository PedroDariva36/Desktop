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
void pt(){
    for(int i = 0 ; i < n; i++){
        cout << t[i] << " ";   
    }
    cout << " - ";
    for(int i = n ; i < n+n; i++){
        cout << t[i] << " ";   
    }
    cout << endl;
}
/*
void update(int p, int v){
    for(t[p] = v; p > 1; p >>= 1)
        t[p>>1] = t[p] + t[p^1];
}
*/

void query(int v){
    int p = 1;
    while (p < n) {
        t[p]--;
        if(t[p<<1] >= v) 
            p = p<<1;
        else{
            v-= t[p<<1]; 
            p = (p<<1) + 1;
        }
    }
    t[p]--;
    cout << a[p-n] << " ";
}



int main (int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s, k;
    ll aux;
    cin >> s;
    
    n = 1;
    while (n < s) n <<= 1;
    
    for (int i = 0; i < s; i++){
        cin >> aux;
        a.push_back(aux);
        t[i+n] = 1;
    }

    build();

    for (int i = 0; i < s; i++) {
        cin >> k;
        query(k);
    }
    cout << endl;
    return 0;
}
