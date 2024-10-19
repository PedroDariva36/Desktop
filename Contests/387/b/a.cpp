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
    while(tt--){
        int n;
        cin >> n;
        vector<char> a(n);    
        for(auto &i: a) cin >> i; 
    
        if(n%4 != 0) {
            cout << "===" << endl;
            continue;
        }


        array<int, 5> sum,asw;
        
        for(int i = 0; i < 5; i++){
            sum[i] = 0;
            asw[i] = 0;
        }


        for(int i = 0; i < n; i++){
             if(a[i] == 'A') sum[0] += 1;
             if(a[i] == 'C') sum[1] += 1; 
             if(a[i] == 'G') sum[2] += 1; 
             if(a[i] == 'T') sum[3] += 1; 
             if(a[i] == '?') sum[4] += 1; 
        }
  
        int t = max(max(sum[3], sum[2]),max(sum[0],sum[1]));
        for(int i = 0; i < 4; i++){
            int x = t - sum[i];
            sum[4] -= x;
            asw[i] = x;
        }        
        
        if (sum[4] < 0 || asw[4] % 4 != 0){
            cout << "===" << endl;
            continue;
        }

        t = sum[4]/4;
        for(int i = 0; i < 4; i++) asw[i] += t;
        
        for(int i = 0; i < n; i++){
            if(a[i] == '?'){
                int j = 0;
                for(; j < 4; j++) if(asw[j] != 0) break;
                asw[j]--;
    
                if(j == 0) cout << 'A';
                if(j == 1) cout << 'C';
                if(j == 2) cout << 'G';
                if(j == 3) cout << 'T';

            }
            else cout << a[i];

        }
        cout << endl;

    }

    return 0;
}
