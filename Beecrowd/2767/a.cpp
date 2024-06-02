#include <bits/stdc++.h>
#include <vector>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,k,aux;
    while (cin >> n >> m >> k) {
        vector<pair<ll,ll>> a(k);

        for (int i = 0; i < n; i++) {
            cin >> aux;
            a[aux%k].first++;
        }
        
        for (int i = 0; i < m; i++) {
            cin >> aux;
            a[aux%k].second++;
        }
        ll sum = 0;
        for (int i = 0; i < k; i++) {
            sum += (a[i].first * a[(k-i)%k].second);
        }
        
        cout << sum << endl;

        
    }

    return 0;
}
