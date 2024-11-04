#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOMOD = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOMOD);}};
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


const ll MOD = 1e9+7;
vector<vector<char>> g(1000, vector<char>(1000));
vector<vector<ll>> dp(1000, vector<ll>(1000, 0));
int n, m;

ll solve(int x, int y){
    if(x == n-1 && y == m-1) return 1;
    if(dp[x][y] != -1) return dp[x][y];        

    ll i = 0, j = 0;

    if(x+1 < n && g[x+1][y] == '.') i = solve(x+1, y);
    if(y+1 < m && g[x][y+1] == '.') j = solve(x, y+1);

    return dp[x][y] = (i % MOD + j % MOD) % MOD; 
}




int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    while(tt--){

        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> g[i][j];
            }
        }

        dp[0][0] = 1; 
        for(int i = 0; i < n; i++){
           for(int j = 0; j < m; j++){
                for(int k: {i,i+1}){
                    int l = j;  
                    if(k == i) l+=1;
                    if(k >= n || l >= m || g[k][l] == '#') continue;
                    dp[k][l] = (dp[k][l] % MOD + dp[i][j] % MOD) % MOD;
                }
            } 
        }

        cout << dp[n-1][m-1] << endl;  
    }

    return 0;
}
