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


ll calcDist(ll st, ll end, vector<pair<ll,ll>> &g){
  return (ll)abs(g[st].first - g[end].first) + (ll)abs(g[st].second - g[end].second);   
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        ll n, k, st, end;
        cin >> n >> k >> st >> end, st--, end--;
    
        vector<bool> major(n, 0);
        vector<pair<ll,ll>> g(n); 
        
        for(int i = 0; i < n; i++){
            cin >> g[i].first >> g[i].second;
            if(i < k) major[i] = 1;
        }
        
        ll asw = calcDist(st, end, g);
        ll sMajor = asw;
        ll eMajor = asw;

        for(int i = 0; i < k; i++){
            sMajor = min(sMajor, calcDist(st, i, g));
            eMajor = min(eMajor, calcDist(end, i, g)); 
        }

        

        
        asw = min(asw, sMajor + eMajor);

        cout << asw << endl;

    }

    return 0;
}
