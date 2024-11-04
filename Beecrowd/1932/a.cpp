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




ll k = 0;
const ll N = 2e5+1;
const ll INF = -1;
ll memo[N][2] = {0};
ll a[N];
/*
ll solve(ll x, bool c){
    if(x >= a.size()) return 0;
    if(memo[x][c] != INF) return memo[x][c];

    ll l = 0;
    if(!c) 
        l = solve(x+1,!c) - a[x] - k;  
    else 
        l = solve(x+1,!c) + a[x];

    memo[x][c] = max(l, solve(x+1,c));
    return memo[x][c];
}
*/


int main (){
    cin.tie(0)->sync_with_stdio(0);
    ll n; 
    while(cin >> n >> k){
        for(int i = 0; i < n; i++){
            cin >> a[i];
            memo[i][0] = 0;
            memo[i][1] = 0;
        }
        for(int i = n-1; i >= 0; i--){
            memo[i][1] = max(memo[i+1][0] + a[i], memo[i+1][1]);
            memo[i][0] = max(memo[i+1][1] - a[i] - k, memo[i+1][0]);
        } 
    
        cout << memo[0][0] << endl;

    }

    return 0;
}
