#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;




bool prime(ll n) {
    if (n < 2) return false;
    for (ll x = 2; x*x <= n; x++) {
        if (n%x == 0) return false;
    }
    return true;
}


int main (int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0); 
    int t;
    cin >> t; 
    while (t--) {
        ll n;
        cin >> n;
        ll last = 0;
        vector<ll> a;
        while (n > 1) {
            a.push_back(n);
            if (prime(n)) {
                n--;
                continue;
                last = 0;
            }    
            ll on = n;
            for (ll i = 2; i*i <= n; i++) {
                if (n%i == 0) {
                    
                    if (n/i != i && n/i != last) {
                        n-= n/i;
                        last = n/i;
                        break;
                    }

                    if (i != last){ 
                        n -= i;
                        last = i;
                        break;
                    }
                } 
            }
            if (on == n) {
                n--; 
            }
        }

        cout << a.size()+1 << endl;
        for(auto &i: a)
            cout << i << " ";
        cout << 1 << endl;
    }

    return 0;
}
