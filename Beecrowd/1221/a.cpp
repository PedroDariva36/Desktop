#include <bits/stdc++.h>
#include <ios>
#define ll long long
using namespace std;

ll modpow(ll x, ll n, ll m) {
    if (n == 0) return 1%m;
    long long u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}

bool check_composite(ll n, ll a, ll d, int s) {
    ll x = modpow(a, d, n);
    if (x == 1 || x == n - 1)
        return false;

    for (int r = 1; r < s; r++) {
        x = x * x % n;
        if (x == n - 1) return false;
    }

    return true;
};

bool millerRabin(ll n) { // returns true if n is prime, else returns false.
    if (n < 2) return false;

    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;

        ll k = check_composite(n, a, d, r);
        if (k) return false;
    }
    return true;
}


int main (int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << ((millerRabin(n))? "Prime": "Not Prime") << endl;
    }
    return 0;
}
