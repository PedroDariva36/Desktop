#include <bits/stdc++.h>
#include <cmath>
#define ll long long
using namespace std;
int t;
ll x;
// 1753413055

ll eq(ll i){
    return 3 * (i*i + i)/2 - i;
}

int main (int argc, char *argv[]){
    cin >> t;
    while (t--) {
    
        ll max = 1753413055;
        ll mid = max/2;
        ll low = 1;
        ll old;

        cin >> x;
        while (low < max) {
            if (x == eq(mid) || mid == old) break;
            else if (x > eq(mid)) low = mid;
            else max = mid; 
            old = mid;
            mid = low + (max - low)/2;
        }
    
        cout << mid << endl;
    }
    return 0;
}
