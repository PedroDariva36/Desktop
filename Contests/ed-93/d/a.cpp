#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <iterator>
#include <queue>
#include <tuple>
using namespace std;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);}};
template<typename T, typename comp_function = less<T>> using indexed_set = class __gnu_pbds::tree<T, __gnu_pbds::null_type, comp_function, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<typename K, typename V> using hash_map = unordered_map<K, V, custom_hash>;
template<typename T> using hash_set = unordered_set<T, custom_hash>;

#define ll  long long
#define ull unsigned long long
#define lld  long double
const lld pi = 3.14159265358979323846;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

// const ll mod = 1000000007;
// const ll mod = 998244353;




int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    while(tt--){
        int R, G , B; 
        cin >> R >> G >> B;
        
        vector<int> a(R), b(G), c(B);

    


        for(auto &i: a) cin >> i;
        for(auto &i: b) cin >> i;
        for(auto &i: c) cin >> i;


        sort(all(a));
        sort(all(b));
        sort(all(c));


        vector<vector<vector<ll>>> dp(R+1, vector<vector<ll>>(G+1, vector<ll>(B+1,-1)));
        dp[0][0][0] = 0; 
        for(int i = 0; i <= R; i++){ 
            for(int j = 0; j <= G; j++){
                for(int k = 0; k <= B; k++){
                    

                    if(i < R) dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] );
                    if(j < G) dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k] );
                    if(k < B) dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k] );


                    if(i < R && k < B) 
                        dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k] + a[i]*c[k]);
                    if(i < R && j < G) 
                        dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k] + a[i]*b[j]);
                    if(j < G && k < B) 
                        dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k] + b[j]*c[k]);
                }
            }
        }

        cout << dp[R][G][B] << endl;

    }
    return 0;
}
