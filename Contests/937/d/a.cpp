#include <bits/stdc++.h>
#include <cmath>
#define ll long long


ll a[] = {1,2,4,8,16,32};

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll k;
        for (int i = 32; i > 0; i--) {
            k = 0; 
            for (int j = 0; j < 6; j++) {
                if ((i&a[j]) != 0) {
                    k += pow(10, j);
                } 
            }
            if (k == 1) {
                break; 
            }

            while ((n % k == 0)) {
                n /= k; 
            } 
        }

        cout << (n == 1? "YES": "NO") << endl;


    }

    return 0;
}
