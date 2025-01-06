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

ll tester( vector<int> &a){
    ll sum = 0;
    int n = a.size();
    for(int i = 0; i < n; i++){
        ll mn = 1e9;
        for(int j = i; j < n; j++ )
            mn = min(mn, (ll)a[j]), sum += mn;

    } 

    return sum;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        ll n, k;
        cin >> n >> k;
        
        if(n <= 60 && 1ll<<(n-1) < k){
            cout << -1 << endl;
            continue;
        } 
        
        k--;
        vector<bool> a;
        while (k) {
            a.pb(k%2);
            k >>= 1;             
        }
        while (a.size() < n-1) a.pb(0); 

        vector<int> l, r; 

        for(int i = n-2, j = 1; i >=0; i--,j++){
            if(a[i]) r.pb(j);
            else l.pb(j);
        }
        
        for(auto &i: l) cout << i << " ";
        cout << n << " ";
        reverse(all(r));
        for(auto &i: r) cout << i << " ";
        cout << endl;
            


    }

    return 0;
}
