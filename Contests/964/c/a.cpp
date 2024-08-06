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
        ll n, s, m;
        cin >> n >> s >> m;;
        
        vector<pair<ll,ll>> a;   
        
        ll k,l;
        a.pb({0,0});
        for(int i = 0; i < n; i++){
            cin >> k >> l;
            a.pb({k,l});
        }
        a.pb({m,m}); 
        
        ll mx = 0;
        for (int i = 0; i < a.size()-1; i++) {
            mx = max(mx, abs(a[i].second - a[i+1].first)); 
        }
        
         cout <<(mx >= s?"YES":"NO") << endl;;



    


         


         

    }
    return 0;
}
