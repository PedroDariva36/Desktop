#include <algorithm>
#include <bits/stdc++.h>
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

    ll n, m, f;
    cin >> n >> m;

    vector<ll> a(n);
    for (auto &i: a) {
        cin >> i; 
    } 
    sort(all(a));

    ll mx = 1e12; 
    for (int i = 0; i < n-m; i++) {
        ll c = 0; 
        ll k = a[i]; 
        map<ll,int> mp; 
        while (a[i] > 0) {
            mp[a[i]] = c++;
            a[i] >>= 1;
        } 
        c = 0;
        for (int j = i+1; j < i+m;j++) {
            ll b = a[j];
            ll local = 0; 
            while (mp.count(b) == 0){
                b>>=1;
                local++;
            }
            if(mp[k] < mp[b]){
                c += abs(j-i)*abs(mp[k] - mp[b]);
                k = b;  
            }
            c += local;
        }  
        mx = min(c, mx);
    }

    cout << mx << endl; 

    return 0;
}
