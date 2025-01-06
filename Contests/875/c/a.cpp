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

void dfs(ll x, ll idx, vector<vector<pair<ll,ll>>> &g, vector<ll> &m){
    for(auto &i: g[x]){
        auto &[y, pos] = i;
        if(m[y] != 1e12) continue; 

        if(pos < idx) m[y] = m[x] + 1;
        else m[y] = m[y] = m[x];
        dfs(y,pos, g, m);
    }
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
   
        
        vector<vector<pair<ll,ll>>> g(n);
        vector<ll> marked(n, 1e12);
    
        ll idx = 1e18;

        for(ll i = 0, x, y; i < n-1; i++){
            cin >> x >> y;
            if(x == 1 || y == 1 ) idx = min(idx, i);
            g[x-1].pb({y-1, i});
            g[y-1].pb({x-1, i});
        }

        marked[0] = 1;     
        dfs(0, idx, g, marked);
    
        ll mx = 1;
        for(auto &i: marked) {
            mx = max(mx, i);

        }
        cout << mx << endl;
            


    }

    return 0;
}
