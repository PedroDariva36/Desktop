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
        int i = 0;
        ll k = 0;
        for (; i < 63; i++) {
            k = 1LL << i;
            if (k > n) {
              i--;
              break;
            }
        }
        cout << (1LL << i) << endl;

        
    }

    return 0;
}
