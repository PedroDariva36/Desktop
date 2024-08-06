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
        ll n, m;
        cin >> n >> m;
    
    
        ll mx = 1;
        ll pt = 1;
        while (pt <= n*m) {
            if(pt%n == 0){
                mx = max(mx,pt);
            }
            pt *= 10;
        }
    

        if(mx == 1){
            pt = 1;
            while (pt * 10 <= m) {
                pt *= 10;
            } 

            if(pt == 1){
                cout << n*m << endl;
                continue;
            }

            ll l = m/pt;
            cout << n * pt *l << endl; 
            continue; 
        }
       

        ll k = mx/n;
        ll l = m/k;
        cout << k*n*l << endl;







        
         

    }
    return 0;
}
