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
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> pref; 
        for(auto &i: a) cin>>i;


        ll sum = 0;
        for (int i = 0; i < n; i++){ 
            (i%2 == 0? sum += a[i] : sum -= a[i]);
            pref.pb(sum); 
        } 

        map<ll,ll> m;
        bool f = 0;
        for (int i = 0; i < n; i++){
            if(pref[i] == 0) f = 1;
            if(m[pref[i]]) f = 1; 
            m[pref[i]]++;
        }


        cout << (f?"YES":"NO") << endl;

         

    }
    return 0;
}
