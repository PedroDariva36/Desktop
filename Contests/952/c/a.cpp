#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

int main (int argc, char *argv[]){
    //cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        vector<ll> p;
        
        ll sum = 0;
        for (auto &i: a) {
            cin >> i;
            p.push_back(i + sum);
            sum += i;
        }
        
        ll c = 0;
        ll mx = 0;
        for (ll i = 0; i < n; i++) {
            if(i == 0 && a[i] == 0 ) {
                c++;
                continue;
            }
            
            mx = max(mx,a[i]);
            if(mx == p[i] - mx) c++;
        }
        
        cout << c << endl;



    }

    return 0;
}
