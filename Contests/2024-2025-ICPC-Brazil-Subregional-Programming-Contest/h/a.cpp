#include <algorithm>
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
    //cin >> tt;
    while(tt--){
        string t, h;
        cin >> t >> h; 
        
        int l = 0;
        for(auto &i: t) if(i == '*') l++;
        for(auto &i: h) if(i == '*') l++;
    

        bitset<32> b;
        int k,c,mod,v;
        for(int i = 0; i < (1<<l); i++){
            b = i; 
            k = 0;
            c = 0;
            
            for(auto &i: h){
                v = (i == '*'? b[k++]: i-'0');
                c = (c<<1) + v; 
            }  
            if(c == 0) continue; 
            
            mod = c; 
            c = 0;
            
            for(auto i: t){
                v = (i == '*'? b[k++]: i-'0');
                c= (c<<1) + v;
                c %= mod;
            } 
            if(c == 0) break;
        }
        
        string s, s2;
        k = 0;
        for(auto &i: h) s2.pb(i == '*'? b[k++] + '0': i);
        for(auto &i: t) {
            s.pb(i == '*'? b[k++] + '0': i);
        }

        cout << s << endl;

    }

    return 0;
}
