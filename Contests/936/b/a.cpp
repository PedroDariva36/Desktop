#include <bits/stdc++.h>
#include <vector>
#define ll long long

const ll mod = 1e9+7;

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        ll aux;
        cin >> n >> k;
        vector<ll>a; 
        ll ms = 0;
        ll sl = 0;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            sl = max(aux,sl+aux);
            ms = max(ms,sl);       
            a.push_back(aux); 
        }

        ll sum = ms;
        for (int i = 0; i < k; i++) {
            sum = (((sum << 1)%mod)+mod)%mod;
        }


        for (auto &i : a) {
            sum = (((sum + i)%mod)+mod)%mod;
        }
       sum = (((sum - ms)%mod)+mod)%mod; 
    
        cout << sum << endl; 
    }

    return 0;
}
