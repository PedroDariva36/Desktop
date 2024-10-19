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
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, k;
        cin >> n >> k;
    
        vector<ll> a(n), h(n), d(n,0);
            
        for(auto &i: a) cin >> i;
        for(auto &i: h) cin >> i;
        

        for (int i = 0; i < n-1;i++)
            if(h[i]%h[i+1] == 0) 
                d[i] = 1;
        
        int first = -1;
        ll sum = 0;
        int mx = 0;
        for (int i = 0; i < n; i++ ) {
            if(first == -1 && d[i] == 0){
                if(a[i] > k) continue;
                mx = max(mx, 1);
                continue; 
            }

            if(first == -1){
                if(a[i] > k) continue; 
                first = i;
                sum += a[i];
                mx = max(mx, abs(i-first + 1));
                continue;
            }
    
            if(a[i] > k){
                first = -1;
                sum = 0;
                continue;
            } 

            if(d[i] == 0){
                sum += a[i];                
                while(sum > k){ 
                    sum -= a[first]; 
                    first++; 
                }
                
                mx = max(mx, abs(i-first + 1));
                first = -1;
                sum = 0;
            }
            
            else {
                sum += a[i];                
                while(sum > k){ 
                    sum -= a[first]; 
                    first++; 
                }    
                mx = max(mx, abs(i-first + 1));
            }
        } 

        cout << mx << endl;








    }
    return 0;
}
