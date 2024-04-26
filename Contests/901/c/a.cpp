#include <bits/stdc++.h>
#include <numeric>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        
        if (n % k == 0) {
            cout << 0 << endl; 
            continue; 
        }
        
        n = n % k;
        ll g = gcd(n, k);
        ll a = n / g;
        ll b = k / g;
        if (__builtin_popcount(b) > 1) {
            cout << -1 << endl;
            continue;
        }
        
        ll sum = __builtin_popcount(a);
        sum *= k;
        sum -= n;
        cout << sum << endl;


    }

    return 0;
}
