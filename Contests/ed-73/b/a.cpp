#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <queue>
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

int dx[] = {2,2,1,1,-1,-1,-2,-2};
int dy[] = {-1,1,-2,2,2,-2,1,-1};
int n;

void dfs(int x, int y, vector<vector<int>> &g, bool last){
        
    if(g[x][y] != -1) return;       
    g[x][y] = last;   

    for(int i = 0; i < 8; i++){
        int k = x + dx[i];
        int l = y + dy[i];
    
        if(k < 0 || l < 0 || k >= n || l >= n) continue;
        if(g[k][l] == -1) dfs(k,l,g,!last);
    }

}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    while(tt--){
        cin >> n;

        vector<vector<int>> a(n, vector<int>(n,-1)); 

        queue<pair<int,int>> q;  
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dfs(i, j, a, 0);
            }
        }

        for(auto &i: a){
            for(auto &j: i) cout << (j == 0? "B": "W");            
            cout << endl;
        }
    }

    return 0;
}
