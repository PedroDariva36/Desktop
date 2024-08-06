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
        ll n , a , b;
        cin >> n >> a >> b;
        
        if(a >= b){
            cout << n*a << endl;
            continue;
        }
        
        ll k = (b-a);
        k = min(k,n); 
        //cout << l << " " << b << " " << k << endl;
        ll mx = ((k*(b + b - k + 1))>>1) + (n-k)*a;
        cout << mx << endl;


        

         

    }
    return 0;
}
