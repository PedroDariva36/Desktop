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


void dfs(int x, vector<bool> &marked, vector<int> &father,vector<vector<int>>& g){
    marked[x] = 1;
    for(auto &i: g[x]){
        if(marked[i]) continue;
        father[i] = x; 
        dfs(i,marked,father,g);
    }
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+m+3);
    

    int k, l;
    for(int i = 1; i <= n; i++){
        cin >> k; 
        for(int j = 0; j < k; j++){
            cin >> l;
            g[l].pb(i+m);
            g[i+m].pb(l);
        }
    }

    vector<bool> marked(n+m+3, 0);
    vector<int> father(n+m+3, -1);
   

    for(int i = 1; i <= n+m; i++)
       if(!marked[i]) 
            dfs(i,marked, father, g); 
    

    int t,x,y;
    cin >> t;
    while(t--){
        cin >> x >> y; 
        
        vector<int> a,b; 
        for(int i = x; i != -1; i = father[i]) a.pb(i);
        for(int i = y; i != -1; i = father[i]) b.pb(i);

        if(a.back() != b.back()){
            cout << -1 << endl;
            continue;
        }

        while (a.size() > 1 && b.size() > 1 && a[a.size()-2] == b[b.size()-2]) {
            a.pop_back(); 
            b.pop_back(); 
        }
       

        cout << (a.size() + b.size())/2 << endl;
        for(auto &i: a) 
            cout << (i > m? i-m : i) << " ";
        for(int i = b.size()-2; i >= 0; i--) 
            cout << (b[i] > m? b[i]-m : b[i]) << " ";
        cout << endl;

    }










    return 0;
}
