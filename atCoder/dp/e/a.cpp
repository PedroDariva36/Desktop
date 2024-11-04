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

   

const ll INF  = 1e12;
int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    while(tt--){
        
        ll n, _W, sum = 0;
 
        cin >> n >> _W;
        vector<ll> a(n); 
        vector<ll> b(n); 
        
        for(int i = 0; i < n; i++)
            cin >> b[i] >> a[i];
         
        for(auto &i: a) sum += i; 
   
        vector<ll> dp(sum+1, INF);
        dp[0] = 0; 
        for(int i = 0; i < n; i++)
            for(int x = sum; x >= a[i]; x--)
               dp[x] = min(dp[x], dp[x - a[i]] + b[i]); 
        
        ll asw = 0;
        for(ll i = 0; i <= sum; i++){
            cout << dp[i] << " ";
            if(dp[i] <= _W)
                asw = max(asw, i);
        } 

        cout << asw << endl;
        
    }

    return 0;
}
