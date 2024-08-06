#include <bits/stdc++.h>
#include <pthread.h>
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
        ll n, k , t;
        cin >> n >> k >> t;
        
        vector<ll> a(n);        
        for (auto &i : a) {
            cin >> i;
        }    
        
        vector<ll> b;
        bool f = 0; 
        for (int i = 0; i < n; i++) {
            if(a[i] > t && !f){
                f = 1;
                b.pb(a[i]);
                continue; 
            }
            if(a[i] <= t){
                f = 0;
                b.pb(a[i]);
            } 
        } 
    


        ll sum = 0;
        ll c = 0;
        for (int i = 0; i < b.size(); i++) {
            if(b[i] <= t){
                c++;
                continue;
            }
            
            if(c >= k) {
                c = c-k +1;
                sum += ((c*c + c)/2);
            } 
            c = 0;
        }
        if(c >= k) {
            c = c-k +1;
            sum += ((c*c + c)/2);
        }        
        cout << sum << endl;


    }
    return 0;
}
