#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back


using namespace std;
const long mod = 1e9+7;


ll modpow(ll x, ll n, ll m) {
    if (n == 0) return 1%m;
    ll u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    long a , b;
    while (t--) {
        cin >> a >> b;
        if (b == 0) {
            cout << 1 << endl;
            continue;
        } 
        if (a == 0) {
            cout << 0 << endl;
            continue;
        }  
        
        cout << modpow(a,b,mod) << endl;
    }

    return 0;
}
