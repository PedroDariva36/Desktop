#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;



const ll m = 1e9+7;


ll binpower(ll n, ll x) {
    ll k = 1;
    n %= m;
    while (x) {
        if (x & 1) k = (k * n) % m;
        n = n * n % m;
        x >>= 1;
    }
    return k;
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll r, l , k;
        cin >> l >> r >> k;
        
        ll x = 9/k + 1;        
        ll sum = (binpower(x, r) - binpower(x, l) + m)%m;
        cout << sum << endl;

    }

    return 0;
}
