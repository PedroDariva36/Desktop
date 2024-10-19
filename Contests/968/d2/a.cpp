#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <vector>
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

ll mex(vector<ll> const& A) {
    set<ll> b(A.begin(), A.end());

    ll result = 0;
    while (b.count(result))
        ++result;
    return result;
}

ll gauss(ll x){
    return (x*(x+1))/2;
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, m;
        cin >> n >> m;
        
        vector<vector<ll>> a(n);   
        vector<ll> d(n,0); 

        for(auto &i: a){
            int k; 
            cin >> k;
            ll aux; 
            for(int j = 0; j < k; j++){
                cin >> aux;
                i.pb(aux);
            }
        }

        for(int i = 0; i < n; i++){
            ll mx = 0; 
            a[i].pb(0); 
            for(int j = 0; j < 3; j++){
                mx = mex(a[i]);
                d[i] = max(d[i],mx);
                a[i].back() = mx;
            }
        }
        
        ll mmex = *max_element(all(d));
        
        sort(rall(d));
        ll sum = 0; 
        for(int i = 0; i < min(n,m+1); i++){
            if(d[i] > i){
                sum += d[i];
            } 
            else{
                sum += i;
            }
        }
        ll l = 0; 
        if(m >= n){
            l = gauss(m);
            l -= gauss(n-1);
        }
        cout << (ll)sum + l << endl; 

    }
    return 0;
}
