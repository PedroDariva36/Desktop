#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        
        ll i; 
        for (i = 1ll; i < n; i++) {
            if (n % i != 0) {
                i--;
                break;
            }
        }
        cout << i << endl;
    }    
        
    return 0;
}
