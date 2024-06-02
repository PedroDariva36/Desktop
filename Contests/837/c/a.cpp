#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

const long N = 1e9;
long sieve[1000000]; 

int main (int argc, char *argv[]){
    //cin.tie(0)->sync_with_stdio(0);
    vector<ll> prime;
    for (ll x = 2; x*x < N; x++) {
        if (sieve[x]) continue;
        for (ll u = 2*x; u*u <= N; u += x) {
            sieve[u] = x;
        }
    }
    
    for (ll i = 2; i*i <= N ; i++) {
        if (sieve[i] == 0){
            prime.push_back(i);
        }
    }
    
    cout << prime.size() << endl;

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll aux;
        cin >> n;

        map<ll,ll> m, c;      
        bool f = false; 
        for (int i = 0; i < n; i++)
            cin >> aux, m[aux]++; 
        
        for (auto &k : m) {
            if (k.second > 1) {
                f = true;
                break; 
            }

            ll i = k.first;

            for (auto &p: prime) {
                if(p*p > i) break;
                if (i%p == 0) {
                    c[p]++;
                    if (i/p != p) c[i/p]++;
                }         
            }
            c[i]++;
        }


        if(!f){
            c[1] = 0;
            for (auto i : c) {
                if (i.second > 1) {
                    f = true;
                    break;
                } 
            }
    
        }


        cout << ((f)? "YES" : "NO") << endl;
    }

    return 0;
}
