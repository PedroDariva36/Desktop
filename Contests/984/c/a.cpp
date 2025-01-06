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
//    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        string s; 
        int n, q;
        cin >> s;
        n = s.size();
        cin >> q; 

        if(n < 4){
            int x, y;
            while (q--) {
                cin >> x >> y;
                cout << "NO" << endl;;
            }
            continue; 
        }

        vector<int> asw(n-3);
        vector<string> a(n-3);
        ll sum = 0;

        for(int i = 0; i + 3 < n; i++){
            for(int j = i; j <= i+3; j++){
                a[i].pb(s[j]);
            }

            if(a[i] == "1100") asw[i] = 1;
            sum += asw[i]; 
        }
    
        while (q--) {
            int x;
            char y;
            cin >> x >> y;
            x--; 

            for(int i = max(x-3,0) ; i <= min((int)a.size()-1, x); i++){
                a[i][abs(x-i)] = y;
    
                if(a[i] == "1100")
                    sum += (asw[i]? 0: 1), asw[i] = 1;
                else 
                    sum += (asw[i]? -1: 0), asw[i] = 0;
            }
            cout << (sum > 0? "YES":"NO") << endl;
        }


    }

    return 0;
}
