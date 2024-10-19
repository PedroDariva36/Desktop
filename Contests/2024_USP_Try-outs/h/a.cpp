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





int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m , ts;
    cin >> n >> m >> ts;
   
        

    vector<tuple<ll,ll,ll>> g[n];
    vector<ll> d(n,1e15);
    vector<ll> marked(n,0);
 


    for(int i = 0; i < m; i++){
        int a, b, x ,y;
        cin >> a >> b >> x >> y;
        g[a-1].pb({b-1,x,y});
        g[b-1].pb({a-1,x,y});
    }
    
    d[0] = ts;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    q.push({d[0],0});
    
    while (!q.empty()) {
        ll c , t;
        tie(t,c) = q.top();
        q.pop();
        
        if (marked[c]) continue;
        marked[c] = true;
        
        for (auto u : g[c]) {
            ll v, x, y;
            tie(v,x,y) = u;
    
        
            ll k = t%(x+y);
            ll w = 0;
            if(k >= x){
                w = x + y - k;
            } 

            if (d[c] + w < d[v]) {
                d[v] = d[c] + w;
                q.push({d[v],v});
            }
        }
    }
    
    cout << d[n-1] << endl;
    

    






    return 0;
}
