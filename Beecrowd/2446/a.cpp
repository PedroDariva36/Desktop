#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    ll n,x;
    while(cin >> x >> n){

        vector<ll> wt(n);
        for (auto &i: wt) {
            cin >> i;
        }

        vector<bool> res(x+5,false);
        res[0] = true;
        for (ll i = 0; i < n; i++) {
            for (ll w = x; w >= 0; w--) {
                if(res[w] && w+wt[i] <= x) res[w+wt[i]] = true;
            }
        }

        cout << (res[x]? "S":"N") << endl;
    }
    return 0;
}
