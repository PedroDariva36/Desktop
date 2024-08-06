#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


ll const N = 2*1e5+2;
int k[N];


int solve(int x){
    if(x == 0) return 0; 
    if(k[x] == -1){
        k[x] = 1+solve(x/3);
    }
    return k[x];
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    
    vector<int> pref;
    for(int i = 0; i < N; i++) k[i] = -1;
    ll m = 0;
    for(int i = 0; i < N; i++) {
        m += solve(i);
        pref.pb(m);
    }

    

    while (tt--) {
        ll a,b;
        cin >> a >> b;

        

        cout << pref[b] - pref[a] + 2*solve(a) << endl;
        
    }
    return 0;
}
