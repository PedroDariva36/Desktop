#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

bitset<64> bs;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long k;
        cin >> n >> k;
        
        if (n == 1) {
            cout << k << endl;
            continue; 
        }
        
        int p = 63 - __builtin_clzl(k);
        long x = k - (1 << (p));
        long y = 0;
        long h = (1 << (p-1));

        while (h > 0) {
            if ((h & x) == 0){
                y += h;
            }
            h >>= 1;
        }
        n-=3;
        k -= (x+y);
        cout << x << " " << y << " ";
        for (int i = 0 ; i < n ; i ++) {
            cout << 1 << " ";
            k--;
        } 
        cout << k << endl;

    }

    return 0;
}
