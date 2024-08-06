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
    int tt;
    cin >> tt;
    while (tt--) {
        ll n,k;
        cin >> n >> k; 
        
        if(n == 1||k==1){
            cout << "YES" << endl;
            continue;
        }
        
        vector<ll> a;
        for (ll i = 1; i*i <= n; i++) {
            if(n%i == 0){
                a.pb(i);
                if(n/i != i) a.pb(n/i);
            }
        } 

        ll l = n;
        for (int i = 0; i < a.size(); i++) {
            if(a[i] < l && a[i] != 1){
               l = a[i];  
            }
        } 
            


        bool f = (l > k);
        cout << (f?"YES":"NO") << endl;

         

    }
    return 0;
}
