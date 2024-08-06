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

    
ll solve(ll x, vector<ll> a){
    ll c = 0;
    for (int i = 0; i < a.size(); i++) a[i] = abs(a[i] - x);
    
   
    return is_sorted(all(a));
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
    
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i]; 
        } 

        ll last = 0;
        ll l = 0, r = 2*(*max_element(all(a)));
        while (l < r) {
            
            ll mid = (l+r)/2; 
            ll aux = solve(mid,a);  
            if(aux > last){
                r = mid;
            }
            else{   
                l = mid + 1;
            }
        }
        
        if(solve(l, a)){
            cout << -1 << endl;
            continue;
        }
        
        cout << r << endl;


    }
    return 0;
}
