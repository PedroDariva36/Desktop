#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#define ll long long
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n+1);
        a[0] = 0;
        for (int i = 1 ; i<=n ; i++) {
            cin >> a[i];
        }
        int l, r;
        while (q--) {
            cin >> l >> r;
            if (l == r) {
                cout << "NO" << endl;
                continue;
            }
            unordered_map<ll, ll, custom_hash> m;
            for (int i = l; i <= r; i++) {
                m[a[i]]++;        
            }
            bool f = true;
            for (auto &i : m) {
                if( i.second > (r-l+1)/2){
                    f =false;
                    break;
                }
            }
            if(f) cout << "YES" << endl;
            else cout << "NO" << endl;

        }

    }

    return 0;
}
