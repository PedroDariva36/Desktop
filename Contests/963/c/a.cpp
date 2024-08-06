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
        int n;
        ll k;
        cin >> n >> k;
    
        vector<ll> a(n);
                
        
        for(auto &i: a){
            cin >> i;
        }
        

        
        sort(rall(a));
        ll mx= a[0];  
        bool f = 0; 
        for (ll i = 1; i < n; i++) {
            if(a[i] + k < mx){
                ll l = (mx+k - a[i])/(2*k);
                a[i] += 2*k*l;
            }
        }
        
        sort(all(a));
    
        if(abs(a.front() - a.back()) >= k) f= 1;

        if(f){
            cout << -1 << endl;
            continue;
        }
        /*  
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        */
        //cout << endl;
        cout << *max_element(all(a))  << endl;


         

    }
    return 0;
}
