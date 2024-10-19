#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
#include <queue>
#include <vector>
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

vector<int> m(1001,0);
void sieve(int n){
    m[0] = 1;
    m[1] = 1;
    for(int i = 2; i < n; i++){
        for(int j = i; j < n; j+=i){
            if(m[j]) continue;
            m[j] = i;
        }
    }
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    sieve(1001);

    int tt;
    cin >> tt;
    while (tt--) {
        int l, r;
        cin >> l >> r;
    
        map<int,int> g;

        for(int i = l; i <= r; i++){
            g[m[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; 
        for(auto &i: g) q.push(i);
 

        ll sum = 0;
        while (q.size() >= 3) {
            auto x = q.top();q.pop(); 
            auto y = q.top();q.pop(); 
            auto z = q.top();q.pop();

            int k = min(x.second,min(y.second,z.second));
            x.second-=k; 
            y.second-=k; 
            z.second-=k; 

            sum+=k;

            if(x.second > 0) q.push(x);
            if(y.second > 0) q.push(y);
            if(z.second > 0) q.push(z);
        }

        cout << sum << endl;



    }
    return 0;
}
