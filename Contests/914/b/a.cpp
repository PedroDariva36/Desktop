#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<ll> a(n),b(n),pre(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i]; 
        }

        sort(all(b));
        ll sum = 0; 
        for (int i = 0; i < n; i++) {
            sum += b[i];
            pre[i] = sum;
        }
        
        for (int i = 0; i < n; i++) {
            ll k = a[i];
             
            int l = 0;
            int r = n-1;
            while (l < r) {
                  
            }




        }
        





    }

    return 0;
}
