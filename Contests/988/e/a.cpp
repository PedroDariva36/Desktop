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


int query(int a, int b){
    int k = 0;
    cout << "? " << a << " " << b << endl; 
    cout.flush();
    cin >> k;
    return k;
}


int main (int argc, char *argv[]){
    //cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;

        bool f = 0;
        vector<int> b(n,-1);
        
        int k, last = 0, general;
        int l = 0 ,r = n-1;

        general = query(1, n);
        
        if(n == 2 && general == 1){
            cout << "! 01" << endl;
            cout.flush();
            continue; 
        }


        if(general == 0) {
            cout << "! IMPOSSIBLE" << endl;
            cout.flush();
            continue;
        }
       
        
        last = general;
        for(int i = n-2; i > 0; i--){
            k = query(1, i+1);
            b[r] = (k < last? 1: 0);
            last = k;

            if(i == 1 && k != 0){
                b[0] = 0;
                b[1] = 1;
            }

            if(k == 0){
                b[r-1] = 0;
                b[r] = 1;
                r--;
                break;
            }
            r--;
        }

        last = general;
        while (l < r) {
            if(b[l] != -1) break;
            k = query(l+2, n); 
            b[l++] = (k < last? 0: 1);
        }



        cout << "! ";
        for(auto &i: b) cout << i;
        cout << endl;
    }
    return 0;
}
