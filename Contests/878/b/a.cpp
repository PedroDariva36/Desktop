#include <bits/stdc++.h>
#include <bitset>
#include <vector>
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
        ll n, k;
        cin >> n >> k;
        k = min(k, 32ll);
        
        cout << min(n+1, (1ll << k)) << endl;; 



    




        
         

    }
    return 0;
}
