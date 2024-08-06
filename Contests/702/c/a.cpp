#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long 
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(x) push_back(x)


using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, k;
        bool f = false;        

        cin >> n;
        if(n == 1){
            cout << "NO" << endl;
            continue;
        }
        
        if(n == 2){
            cout << "YES" << endl;
            continue;
        }


        for (ll i = 1; i*i*i <= n; i++) {
            ll k = i*i*i; 

            ll l = 1 , r = sqrt(n); 
            while (l < r) {
                ll mid = (l+r)>>1;
                ll mk = mid*mid*mid;

                if(mk + k == n) {
                    f = true;
                    break;
                }
                ((mk + k > n)? r = mid : l = mid+1);
            }
            if(f) break;
        }

        cout << (f? "YES" : "NO") << endl; 


         

    }
    return 0;
}
