#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        
        if (n == 1 || k == 1) {
            cout << 1 << endl;
            continue; 
        }
        
        if(n % 2 == 1) n++;

        if (k <= n/2) {
            cout << 1+(2*(k-1)) << endl;
            continue;
        }
        ll r = 1;
        while (k) {
         
        }     
    


    
        cout << ((2*r)*(k-1)) << endl;
        continue;

        


    }


    return 0;
}
