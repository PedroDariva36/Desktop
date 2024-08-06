#include <bits/stdc++.h>
#include <unistd.h>
#include <vector>
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
        vector<ll> a(n), b(n);
        for (auto &i: a) cin >> i;
        for (auto &i: b) cin >> i;
        
        ll mx = -1e10;
        for (int i = 0; i <n; i++) 
            mx = max(mx, a[i] - b[i]);  
        
        vector<ll> c;
        for (int i = 0; i <n; i++) 
            if (a[i] - b[i] == mx) c.pb(i+1);

        cout << c.size() << endl;
        for (auto i: c) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
