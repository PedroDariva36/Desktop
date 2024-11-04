#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <utility>
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


const int N = 5e5+1;
array<int, N> father;
array<int, N> rk;


void make_set(int v) {
    father[v] = v;
    rk[v] = 0;
}

int find_set(int v) {
    if (v == father[v])
        return v;
    return father[v] = find_set(father[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap(a, b);
        father[b] = a;
        if (rk[a] == rk[b])
            rk[a]++;
    }
}

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n , m; 
    while(cin >> n >> m && m != 0){
        for(int i = 0; i < n; i++)
            make_set(i);
   
        vector<tuple<ll,int,int>> e;
        

        int a, b;
        ll c;
        while(m--){
            cin >> a >> b >> c;            
            e.pb({c,a,b});    
        }

        sort(all(e));    
        ll sum = 0;    
        for(auto &i: e){
            tie(c,a,b) = i; 
            if(find_set(a) != find_set(b)){
                union_sets(a,b);
                sum += c;
            }   
        }
        cout << sum << endl;
        
    }



    return 0;
}
