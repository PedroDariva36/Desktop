#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);}};
template<typename T, typename comp_function = std::less<T>> using indexed_set = class __gnu_pbds::tree<T, __gnu_pbds::null_type, comp_function, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<typename K, typename V> using hash_map = std::unordered_map<K, V, custom_hash>;
template<typename T> using hash_set = std::unordered_set<T, custom_hash>;
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


const ll mod = 998244353;
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a){
    return binpow(a,mod-2, mod);
}



int main (int argc, char *argv[]){
    ios::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr); 
    int tt = 1;
    cin >> tt;
    while(tt--){
        int n, q;
        cin >> n >> q;
   
        vector<ll> c(n),d(n);
        
        vector<ll> a;
        vector<ll> b;
      

        for(auto &i: c) cin >> i;
        for(auto &i: d) cin >> i;
    
        a = c;
        b = d;
   
        sort(all(a));
        sort(all(b));

        ll sum = 1;
        for(int i = 0; i < n; i++){
            ll k = min(a[i],b[i]);
            sum *= k;
            sum %= mod;
        }

        cout << sum << " "; 

        for(ll i = 0, op, x; i < q; i++){
            cin >> op >> x;

            x--;    
            if(op == 1){
                ll k = c[x]++; 
                int r = upper_bound(all(a), k) - a.begin()-1;
                ll v = min(a[r], b[r]); 
                a[r]++;
                sum *= min(a[r], b[r]);
                sum %= mod;
                sum *= modinv(v);
                sum %= mod; 
            }
            else{
                ll k = d[x]++; 
                int r = upper_bound(all(b), k) - b.begin()-1;
                ll v = min(a[r], b[r]); 
                b[r]++;
                sum *= min(a[r], b[r]);
                sum %= mod;
                sum *= modinv(v);
                sum %= mod; 
            } 
            cout << sum << " ";
        }
        cout << endl;
        


    }

    return 0;
}
