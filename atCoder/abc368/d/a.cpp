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

set<int> rq;




ll asw = 0;
bool dfs(ll x, vector<vector<int>> &g, vector<bool> &m){
    if(m[x]) return false;
    m[x] = true;

    bool q = rq.count(x);
    bool f = 0; 

    for(auto &i: g[x]){
        ll aux = dfs(i, g,m);
        f = f | aux;
    }
    
    asw += (q|f);

    return q | f; 
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
        int n, k;
        cin >> n >> k;
        vector<vector<int>> g(n);
        vector<bool> marked(n);
    


        for(int i = 0; i < n-1; i++){
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            g[a].pb(b);
            g[b].pb(a);
        }

        for(int i = 0; i < k; i++){
            int a;
            cin >> a;
            rq.insert(a-1);
        } 

        dfs(*rq.begin(), g, marked);
        cout << asw << endl;

     







    return 0;
}
