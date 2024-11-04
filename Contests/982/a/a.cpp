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

int dx[] = {0, 0 ,-1, 1};
int dy[] = {-1, 1 ,0, 0};

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        int x, y; 
        vector<vector<bool>> a(100, vector<bool>(100,0));
        set<pair<int,int>> s;
        for(int k = 0; k < n; k++){
            cin >> x >> y;
            s.insert({x,y});
        }

        for(auto &k: s){
            x = k.first; 
            y = k.second; 
            for(int i = 0; i < x; i++)
                for(int j = 0; j < y; j++)
                    a[i][j] = 1; 
        }        

        ll sum = 0;
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                if(!a[i][j]) continue;
                int local = 0; 
                for(int k = 0; k < 4; k++){
                    if(i + dx[k] < 0) continue;
                    if(i + dx[k] >= 100) continue;
                    if(j + dy[k] < 0) continue;
                    if(j + dy[k] >= 100) continue;
                    local += a[i + dx[k]][j + dy[k]];
                } 
                sum += (4-local);
            }
        }
        cout << sum << endl;
    }

    return 0;
}
