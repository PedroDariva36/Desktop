#include <bits/stdc++.h>
#include <unistd.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


ll gauss(ll a){
    ll k = (a*(1 + a));
    k >>= 1;
    return k;
}
 
ll gauss2(ll k , ll n){
    ll l = (k*((n-(k-1)) + n));
    l >>= 1;
    return l;
}   



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n , k, x;
        cin >> n >> k >> x;
        
        if(x < n){
            cout << ((gauss(k) <= x)? "YES":"NO") << endl;
        }
        else {
            if(gauss2(k, n) >= x){
                cout << ((gauss(k) <= x)? "YES":"NO") << endl;
                continue;
            }
            cout << "NO" << endl;
        }
        




         
        



         

    }
    return 0;
}
