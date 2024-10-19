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

vector<ll> path;
ll st,ed;
ll k = 0;
ll memo[1123][11234] = {0};

int dfs(ll a, ll l, vector<vector<pair<ll,ll>>> &g){
    if(memo[a][l]) return 0;
    if(a == ed && k == l){
        path.pb(a);
        return 1;
    }
    memo[a][l] = 1; 

    int aux = 0;
    for(auto &i: g[a])
        if(l + i.second <= k) 
            aux = max(aux, dfs(i.first,l+i.second,g));
    
    if(aux > 0){
        path.pb(a);
        return 1;
    }
    
    return 0;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m;
    cin >> n >> m >> k;
    vector<vector<pair<ll,ll>>> g(n+1);
    cin >> st >> ed;

    ll a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }
    
    

    bool f = dfs(st,0,g); 
    
    if(f){
        reverse(all(path));
        for(auto &i: path) cout << i <<  " ";

    }
    else cout << "Impossible";
    cout << endl;




    return 0;
}
