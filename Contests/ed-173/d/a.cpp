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




int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        ll l, r , g;
        cin >> l >> r >> g;

        l += (l%g == 0? 0: g - (l%g));
        r -= r%g;
        ll x = -1, y = -1;
        for(int i = 0; i <= (r-l)/g; i++){ // (r-l)/g - 0 , - g, - 2g, ... -(r-l)/g;
            if(x != -1) break; 
            for(int j = 0; j <= i; j++){ 
                if(gcd(l + j*g, r - (i-j)*g) == g){ // it goes {0 i}, {1,i-1}, {2, i-2}, ... , {i, 0};
                    x = l + j*g;
                    y = r - (i-j)*g;
                    break;
                }
            }
        }

        cout << x << " " << y << endl;


            
        
    





    }

    return 0;
}
