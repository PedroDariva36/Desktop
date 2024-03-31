#include <bits/stdc++.h>
#include <numeric>
#define ll long long

using namespace std;

bool prime(ll n) {
    if (n < 2) return true;
    for (ll i = 2; i*i <= n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);    
    int t;
    cin >> t;
    while (t--) {
        ll l , r;
        cin >> l >> r;
        ll x = -1;
        for (ll k = l; k <= r; k++) {
            if (prime(k)) continue;    
            else{
                x = k;
                break;
            } 
        }
        if (x == -1) {
            cout << x << endl; 
            continue; 
        }

        for (ll i = 2; i*i <= x; i++) {
            if (x % i == 0) {

                cout << x - i << " " << i << endl;
                break;
            }
        }
        


        


    }
    
    return 0;
}
