#include <bits/stdc++.h>
#include <cmath>
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
        int n, m;
        cin >> n;
    
        vector<pair<int,int>> a(n);
        vector<pair<int,int>> b; 
        for(int i = 0, l, r, x, y; i < n; i++){
            cin >> l >> r >> x >> y;
            a[i].first = l, a[i].second = y;
        } 
        cin >> m;
        vector<int> q(m);
        for(auto &i: q) cin >> i;

        sort(all(a)); 
        
        auto last = a.front();
        for(int i = 1; i < n; i++){
            if(a[i].second <= last.second) continue;
        
            if(a[i].first <= last.second){
                last.second = a[i].second;
            }
            else{
                b.pb(last);
                last = a[i];
            } 
        } 
        b.pb(last);

//        for(auto &i : b) cout << i.first << " " << i.second << endl;


        for(auto &i: q){
            ll l = 0, r = b.size()-1;
            while (l < r) {
                ll mid = (l+r+1)>>1; 
                if(b[mid].first <= i)
                    l = mid;
                else
                    r = mid-1;
            }
    
            if(b[r].first <= i && i <= b[r].second){
                cout << b[r].second << " ";
            }
            else cout << i << " "; 
        }    
        cout << endl;



    }

    return 0;
}
