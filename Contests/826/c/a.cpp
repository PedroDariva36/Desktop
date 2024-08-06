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
        vector<ll> a(n),pref;

        for(auto &i: a){
            cin >> i;
            sum += i; 
            pref.pb(sum);
        } 
        ll mn = n; 
        for (int i = 0; i < n; i++) {
            ll tsum = pref[i];
            ll lsum = 0; 
            bool f = 0;
            ll lmx = i+1;

            int j = i+1;
            ll c = 0;
            while (j < n) {
                if(lsum < tsum){
                    lsum += a[j];
                    c++;
                    if(tsum == lsum){
                        lmx = max(lmx, c); 
                        lsum = 0;
                        c = 0;
                    }
                }
                if(lsum > tsum){
                    f = 1;
                    break;
                }
                j++;
            }


            if(f) continue;
            if(lsum == 0)
                mn = min(lmx,mn);
        }

        cout << mn << endl;
        
         

    }
    return 0;
}
