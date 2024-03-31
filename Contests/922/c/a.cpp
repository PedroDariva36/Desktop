#include <bits/stdc++.h>
#include <cmath>
#define ll long long


using namespace std;


int t;
int main (int argc, char *argv[]){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> t;
    while (t--){
        ll a, b, r;

        cin >> a >> b >> r;
        
        for (ll i = 0; i <= r; i++) {
            cout << i << ", " << abs((a^i) - (b^i)) << endl;
        }
            

    }
    return 0;
}
