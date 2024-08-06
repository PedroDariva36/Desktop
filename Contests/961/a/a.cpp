#include <bits/stdc++.h>
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
        
        if(k == 0){
            cout << 0 << endl;
            continue;
        }

        ll sum = 1;
        ll t = 1;
        k -= n;
        for (ll i = n-1; i > 0; i--) {
            for (ll j = 0; j < 2; j++) {
                if(k <= 0){
                    break;
                }
                sum++;
                k -= i;
            }
            if(k == 0) break;
            t++;
        }        

        cout << sum << endl;


                
         

    }
    return 0;
}
