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




int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        ll n, m, l;
        cin >> n >> m >> l;
        
        vector<pair<ll,ll>> a(n);
        vector<pair<ll,ll>> b(m);
        
        for(auto &i: a)
            cin >> i.first >> i.second;

        for(auto &i: b)
            cin >> i.first >> i.second;
    
        ll asw = 0;
        ll ac = 0;
        int last = 0;
        bool f = 0;
        
        priority_queue<int> q;
        for(auto &j: a){
            ll k = j.second - j.first;
            for(int i = last; (b[i].first < j.first) && (i < m); i++,last++){
                q.push(b[i].second);
            }
    

            while (k >= ac) {
                if(q.empty()){
                    f = 1;
                    break;
                } 
                ac += q.top(),q.pop(),asw++;
            }
            if(f) break;
        } 
        
        cout << (f? -1 : asw) << endl;


    }

    return 0;
}
