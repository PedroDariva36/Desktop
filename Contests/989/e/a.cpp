#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
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
    int fac[] = {1,1,2,6,24,120,720,5040};
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        int n, k;
        cin >> n >> k;
       
        if(k == 1 && n == 1){
            cout << "YES" << endl;
            cout << 1 << endl;
            continue;
        }

        if(k == 1 || n == 1){
            cout << "NO" << endl;
            continue;
        }

        if(n%2 == 0 && k%2 == 1){
            cout << "NO" << endl;
            continue;
        }

        if(n < 8 && (fac[n] < k || fac[n]-1 == k)){
            cout << "NO" << endl;
            continue;
        }

        vector<vector<int>> a, b;    
        vector<int> p(n), q(n);


        for(int i = 0; i < n; i++) 
            p[i] = i+1;

        
        if(k%2 == 1){
            vector<int> p1(n), p2(n);
            for(int i = 0; i < n; i += 2) p1[i] = (n+1)/2-i/2, p2[i] = n-i/2;
            for(int i = 1; i < n; i += 2) p1[i] = n-i/2, p2[i] = n/2-i/2;

            b.pb(p);
            b.pb(p1);
            b.pb(p2);
            a = b;
            k-=3;
        }
         

        do {
            if(k == 0) break;
            
            for(int i = 0; i < n; i++) 
                q[i] = n+1 - p[i];
            
            
            if(p < q){
                 
                bool f = 0;
                for(auto &i: b) f |= i == p, f |= i == q; 
                if(!f){
                    k-=2;
                    a.pb(p); 
                    a.pb(q); 
                }
            }

        } while (next_permutation(all(p))); 


        cout << "YES" << endl;
        for(auto &i: a){
            for(auto &j: i) cout << j << " ";
            cout << endl;
        }

    }

    return 0;
}
