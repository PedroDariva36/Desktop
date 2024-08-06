#include <algorithm>
#include <bits/stdc++.h>
#include <bitset>
#include <cstdlib>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


bitset<64> a;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;

        set<ll> s;
        s.insert(n);
        a = n;
        for (int i = 0; i < 64; i++) {
            if(a[i]){
                ll b = 1ll << i;
                if(n - b > 0) s.insert(n - b);
            } 
        }
        cout << s.size() << endl;
        for (auto i: s) {
            cout << i << " " ;
        }
        cout << endl;

         

    }
    return 0;
}
