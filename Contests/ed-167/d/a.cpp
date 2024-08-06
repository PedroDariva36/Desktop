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
    int n,m;
    cin >> n >> m;
    vector<ll> a(n),b(n);
    vector<ll> c(m);


    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;
    for(auto &i: c) cin >> i;
    ll mx = *max_element(all(a));
    vector<ll> k(mx+1,1e9+7), l(mx+1,0);



    for (int i = 0; i < n; i++) {
        k[a[i]] = min(k[a[i]], a[i] - b[i]);
    }
    for (auto i = 1; i < k.size(); i++) {
        k[i] = min(k[i],k[i-1]); 
    }

    for (int i = 1; i < l.size(); i++) {
        if(i >= k[i]) l[i] = 2 + l[i - k[i]];
    }

    ll sum = 0;
    for (ll &i: c) {
        if (i > mx){ 
            ll d = (i-mx)/k[mx];
            d += (i-mx)%k[mx] != 0;
            i -= d*k[mx];
            sum += d*2;
        }
        sum += l[i];
    }


    cout << sum << endl; 

    return 0;
}
