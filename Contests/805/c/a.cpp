#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
       
        unordered_map<ll, vector<int>,custom_hash> m;
        vector<ll> a(n);   
        for(auto &i: a) cin >> i;

        for (int i = 0; i < n; i++) {
            m[a[i]].pb(i); 
        }        
    
        ll x,y;
        while (q--) {
            cin >> x >> y;
            if(m[x].size() == 0 || m[y].size() == 0){
                cout << "NO" << endl;
                continue;
            }
            cout << (m[x].front() < m[y].back()?"YES":"NO") << endl; 
        }
         



    }
    return 0;
}
