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
        ll n, k;
        cin >> n >> k;
    
        ll asw = 0, aux; 
        for(int i = n; i >= n/2 + n%2; i--){
            int l = k-2; 
            ll ac_p2 = n; 
            ll ac_p1 = i; 
            ll ac = ac_p2 - ac_p1;

            while (ac >= 0 && l >= 0) {
   
                if(ac_p2 < ac_p1)
                    break;

                if(l == 0){
                    asw++;
                    break;
                }   
                ac_p2 = ac_p1;
                ac_p1 = ac; 
                ac = ac_p2 - ac_p1;
                l--;
        
                

            }

        }

        cout << asw << endl;

    }

    return 0;
}
