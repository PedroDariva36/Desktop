#include <bits/stdc++.h>
#include <cfloat>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long aux;
        cin >> n;
        
        ll d1 = 0;
        ll d2 = 0;

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            sum += aux;
            d1 += (aux % 3 == 1 ? 1 : 0);
        }
        ll k = sum % 3; 
        if (k == 0) {
            cout << 0 << endl;
        }
        if(k == 1){
            if (d1) {
                cout << 1 << endl;
            }
            else cout << 2 << endl;
        }
        if(k == 2){
            cout << 1 << endl;
        } 

        
        







    }

    return 0;
}
