#include <bits/stdc++.h>
#define ll long long


using namespace std;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k, asw;
        cin >> n >> k;
        
        ll m = (n << 2) - 4;
        
        if (k <= m) {
            ll mod = k%2;
            asw = k/2 + mod;
        }
        else {
            asw = m/2;
            asw += k-m;
        }
        cout << asw << endl;



    }
    return 0;
}
