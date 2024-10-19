#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
    
        vector<ll> a(n), b(n), c(n);
        
        for(auto &i: a) cin >> i;
        for(auto &i: b) cin >> i;

        ll t = 0;
        for (int i = 0; i < n; i++) {
            c[i] = abs(max(t, a[i]) - b[i]);
            t = b[i];
        }

        for(auto i: c) cout << i << " ";
        cout << endl;


         

    }
    return 0;
}
