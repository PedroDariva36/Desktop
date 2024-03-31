#include <bits/stdc++.h>
#define ll long long

using namespace std;

int a[] = {0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 2, 2, 3, 1, 2, 3, 2, 3, 2, 2, 3, 3, 3, 2, 3, 3, 3, 4, 2};

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    
    while (t--) {
        ll n;
        cin >> n;
        ll sum = 0; 
        ll k = max(0ll, n/15 - 1);
        n -= k*15LL;
        cout << k + a[n] << endl;


        

    }

    return 0;
}
