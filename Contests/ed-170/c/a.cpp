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



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        map<ll,ll> m;
        ll n, k, aux;
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> aux;
            m[aux]++;
        } 
        
        ll best = 0; 
        ll sum = 0;
        vector<vector<ll>> a;
        ll last = m.begin()->first; 
        vector<ll> b;

        for(auto &i: m){
            if(i.first - last > 1){
                a.pb(b);
                b.clear();
                b.pb(i.second);
                last = i.first;
            } 
            else{
                b.pb(i.second);
                last = i.first;
            }
        } 
        a.pb(b); 
        

        for(auto &l: a){
            if(l.size() < k){
                sum = 0;
                for(auto &i: l) sum += i;
                best = max(best,sum);
            } 
            else{
                sum = 0;
                for(int i = 0; i < k; i++){
                    sum += l[i]; 
                }    
                best = max(best, sum); 

                for(int i = k; i < l.size(); i++){
                    sum -= l[i-k];
                    sum += l[i];
                    best = max(best, sum); 
                } 
            }
        }
    
        cout << best << endl;



    }

    return 0;
}
