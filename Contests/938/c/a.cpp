#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long
 
 
using namespace std;
 
int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        
        vector<long> a(n);
        ll local = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            local += a[i];
        }
        
        if (k >= local) {
            cout << n << endl;
            continue;
        }
 
 
        ll sum = 0;
        ll r = k/2;
        ll l = r + k%2;
        
 
 
 
 
            
        for(int i = 0; i < n; i++) {
            if (l < a[i]){
                a[i]-= l;
                break;
            }
            l -= a[i];
            a[i] = 0;
            sum++;
        }
        
        for(int i = n-1; i > 0; i--) {
            if (r < a[i]){
                a[i] -= l;
                break;
            }
            r -= a[i];
            a[i] = 0;
            sum++;
        }
 
 
        cout << sum << endl;
 
    }
 
    return 0;
}
