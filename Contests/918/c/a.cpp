#include <bits/stdc++.h>
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
        int  n;
        ll aux; 
        ll sum = 0;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            sum += aux;
        } 
        
        ll l = 1;
        ll r = 1e9; 
        
        while (l < r) {
            ll m = (l+r)>>1;
            if(m*m >= sum)
                r = m;
            else
                l = m+1;
        }
        
        cout << (r*r == sum? "YES": "NO") << endl;
        
    }

    return 0;
}
