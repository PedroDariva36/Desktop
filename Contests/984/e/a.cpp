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
int n;
pair<int,int> findSeg(int x,int v, char op,vector<vector<int>> &a){
    pair<int,int> asw = {-1,-1}; 
    if(op == '>'){
        int l = 0, r = n-1;
        while (l < r) {
            ll mid = l + ((r-l) >> 1); 
            if(a[mid][x] > v){
                r = mid;     
            } 
            else l = mid+1; 
        }

        if(a[l][x] > v) asw = {l, (int)a.size()-1}; 
    }
    else{
        int l = 0, r = n-1;
        while (l < r) {
            ll mid = l + ((r - l + 1) >> 1);
            if(a[mid][x] < v)
                l = mid;     

            else 
                r = mid-1; 
        }
        if(a[l][x] < v) asw = {0, r};
    }      

    return asw;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int m, q;
    cin >> n >> m >> q;


    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int j = 0; j < m; j++){
        int last = a[0][j]; 
        for(int i = 0; i < n; i++){
            b[i][j] = last|a[i][j];
            last = b[i][j];
        }
    }
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << b[i][j];
        }
        cout << endl;
    }
    */

    while (q--) {
        int k, x, v;
        char op;

        cin >> k; 
        vector<pair<int,int>> seg;

        while (k--) {
            cin >> x >> op >> v;
            seg.pb(findSeg(x-1,v,op, b));
        } 
        sort(all(seg));
        auto c = seg[0];        
        for(auto &i: seg){

            if(c.second < i.first){
                c = {-1,-1};
                break;
            }
            c = {i.first, c.second}; 
        } 
        
        cout << (c.first == -1 || c.second == -1? -1: c.first+1) << endl;; 

    } 

    return 0;
}
