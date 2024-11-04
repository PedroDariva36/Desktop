#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <iterator>
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

void dfs(int x, vector<bool> &m, vector<vector<int>> &g){
    if(m[x]) return;    
    m[x] = 1;   

    for(auto &i: g[x]) dfs(i,m,g);
}
void revDfs(int x, vector<vector<int>> &father, vector<vector<int>> &g, int k){
    father[x].pb(k); 
    for(auto &i: g[x]) revDfs(i,father,g,k);
}  


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> dg(n, 0);
    vector<vector<int>> g(n);
    vector<set<int>> c(n); 
    vector<vector<int>> father(n);
    vector<bool> marked(n);


    for(int i = 0; i < m;i++){
        int a,b; 
        cin >> a >> b, a--, b--;
        g[a].pb(b);
        dg[b]++;
        father[b].pb(a);
    }

    for(int i = 0; i < k; i++){
        int a;
        cin >> a, a--;
        marked[a] = 1;
    }
    
    for(int i = 0; i < n; i++){
        if(dg[i] == 0) revDfs(i,father,g,i);
    }

    for(int i = 0; i < n; i++){
        for(auto &j: father[i]){
            c[j].insert(i);
        } 
    } 

    for(int i = 0; i < n; i++)
        if(marked[i]) 
            dfs(i,marked,g); 
    

    for(int i = 0; i < n; ++i){
        if(marked[i]) cout << i+1 << " ";
    }
    cout << endl;        





    return 0;
}
