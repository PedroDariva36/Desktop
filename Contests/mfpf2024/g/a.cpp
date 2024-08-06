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

ll x;
const ll m = 1e9+7;

ll solve(ll k, int p, vector<ll>&a){
    if(k >= x) return 1; 
    if(k < a[p]) return 0; 
    if(p == a.size()) return 0;
    
    ll sum = (solve(k + a[p], p+1, a)) + (solve(k, p+1, a));
    sum %= m;
    return sum; 

}

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    ll n,k;

    cin >> n >> x >> k; 
    vector<ll> a(n-1);
    for (auto &i : a) {
        cin >> i;
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());     


    vector<ll> res(x+1,0);
    res[k] = 1;   

    for (ll i = 0; i < a.size(); i++) {
        for (int j = x; j >= a[i]; j--) {
            if(res[j]) {
                ll k = j+a[i];
                if(j+a[i] > x) {
                    k = x;
                    res[k]++;
                    res[k] %= m;
                    break; 
                } 
                res[k]++;
                res[k] %= m;
            }
        } 
    }

    cout << res[x] << endl;
    //cout << solve(k,0,a) << endl;;

    return 0;
}
