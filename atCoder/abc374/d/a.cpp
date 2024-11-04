#include <algorithm>
#include <bits/stdc++.h>
#include <bitset>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <iomanip>
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

typedef struct P{
    int x1;
    int y1;
    int x2;
    int y2;
} p;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    while(tt--){
        int n, t, s;
        cin >> n >> t >> s;
        
        vector<p> a(n);
        for(auto &i: a) cin >> i.x1 >> i.y1 >> i.x2 >> i.y2;

        vector<int> perm;
        for(int i = 0; i < n; i++) perm.pb(i);
        long double asw = 1e32;
        do {
            long double sum; 
            bitset<8> b; 
            for(int i = 1; i < 1ll << n; i++){
                sum = 0; 
                b = i; 
                int k = 0, l = 0;
                for(int j = 0; j < n; j++){                   
                    p f = a[perm[j]]; 
                    sum += hypotl(f.x1 - f.x2, f.y1 - f.y2)/s;


                    if(b[j]){
                        sum += hypotl(f.x1 - k, f.y1 - l)/t;
                        k = f.x2;
                        l = f.y2;
                    }
                    
                    else{
                        sum += hypotl(f.x2 - k, f.y2 - l)/t;
                        k = f.x1;
                        l = f.y1;
                    }
                }
                asw = min(asw, sum);
            }

        }while(next_permutation(all(perm)));

        
        printf("%.20Lf\n", asw);


        //cout << setprecision(20) << fixed<< asw << endl;

    }

    return 0;
}
