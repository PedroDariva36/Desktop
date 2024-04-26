#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        
        if (k <= (n/2 + n%2)) {
            cout << (1+2*(k-1)) << endl;
            continue;
        }


        ll p = 0; 
        ll pos = 0;
        ll m = n;
        while (k > m/2 + m%2) {
            k -= (m/2 + m%2);
            m = (m/2);
            p++;
        }
        
        
        ll sum = 2*(k-1);
        sum++;
        sum *= pow(2 ,p);
        cout << sum << endl; 
    }


    return 0;
}
