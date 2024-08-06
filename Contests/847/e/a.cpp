#include <bits/stdc++.h>
#include <bitset>
#include <functional>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


bitset<64> x = 0, a = 0,b = 0;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        ll k = n<<1;     
     
    
        if(k%4 == 0){
            ll a , b;
            a = k/4;
            a *= 3;
            b = k/4;

            if(((a+b)>>1) == n && (a^b) == n){
                cout << a << " " << b << endl;
                continue;
            }
        }
        cout << -1 << endl;
        
         

    }
    return 0;
}
