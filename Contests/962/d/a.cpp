#include <bits/stdc++.h>
#include <unordered_set>
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
        ll n, x, aux;
        ll sum = 0;
        cin >> n >> x;

        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= i && j*i <= n; j++ ) {
                if(i + j > x) break; 
                for (ll k = 1; k <= j; k++) {
                    if((i+j+k > x) || (i*j + j*k + i*k > n)) break; 
                    //cout << i << " " << j << " " << k << endl;
                    if(i == k && i == j){
                        sum += 1;
                    }else if(k == j || j == i || k == i){
                        sum += 3;
                    }
                    else sum += 6;
                }
            }
        }        

        cout << sum << endl;
         

    }
    return 0;
}
