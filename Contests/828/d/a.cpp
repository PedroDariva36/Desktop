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
        

        ll sum = 0;
        vector<ll> a(n),b;

        for(auto &i: a) cin >> i;

        for (int i = 0; i < n; i++) {
            while (a[i]%2 == 0){
                sum++;
                a[i] >>= 1;
            }
        }
        
        ll k = n;
        while (k > 0) {
            ll i = k;
            ll c = 0; 
            while (i%2 == 0) {
                c++;
                i>>=1;
            }
            k--;
            b.pb(c);
        }
        ll asw = 0;  
        sort(rall(b));
        
        
        if(sum >= n){
            cout << 0 << endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            sum += b[i];
            asw++; 
            if(sum >= n) break;
        } 
        
        if(sum < n){
            cout << -1 << endl;
            continue;
        }

        cout << asw<< endl;


        
         

    }
    return 0;
}
