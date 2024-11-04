#include <bits/stdc++.h>
#include <cmath>
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


vector<ll> best(1e5+1, 0);


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    while(cin >> n >> m && n != 0){

        vector<vector<ll>> a(n, vector<ll>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }

       
        
        for(int i = 0; i < n; i++){
            vector<ll> dp(m,0); 
            for(int j = m-1; j >= 0; j--){
                
                if(j+2 < m)
                    dp[j]= max(dp[j],dp[j+2]);
                
                if(j+3 < m)
                    dp[j]= max(dp[j],dp[j+3]);

                dp[j] += a[i][j];
            }
            for(int j = 0; j < m; j++)
                best[i] = max(best[i], dp[j]); 
        } 
         
        vector<ll> dp(n,0); 
        for(int j = n-1; j >= 0; j--){
            if(j+2 < n)
                dp[j]= max(dp[j],dp[j+2]);

            if(j+3 < n)
                dp[j]= max(dp[j],dp[j+3]);

            dp[j] += best[j];
        }

        ll mx = 0; 
        for(int j = 0; j < n; j++)
            mx = max(mx, dp[j]); 

        cout << mx << endl;


    } 

    return 0;
}
