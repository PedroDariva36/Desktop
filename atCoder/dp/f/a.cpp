#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
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



const int INF = 1e9+1;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    while(tt--){
        string s,t;
        cin >> s >> t; 
        vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1,0));
        vector<vector<pair<int,int>>> f(s.length()+1, vector<pair<int,int>>(t.length()+1, {0,0}));
        
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < t.length(); j++){
                if(s[i] == t[j])
                    if(dp[i+1][j+1] < dp[i][j] + 1){
                        dp[i+1][j+1] = dp[i][j] + 1;
                        f[i+1][j+1] = {i,j}; 
                    }                
                
                if(dp[i+1][j] < dp[i][j]){
                    dp[i+1][j] = dp[i][j];
                    f[i+1][j] = {i,j};
                }
                
                if(dp[i][j+1] < dp[i][j]){
                    dp[i][j+1] = dp[i][j];
                    f[i][j+1] = {i,j};
                }
            }
        }


        int asw = 0;
        pair<int,int> pos = {0,0};
        for(int i = 0; i <= s.length(); i++){
            for(int j = 0; j <= t.length(); j++){
                if(asw < dp[i][j]){  
                    asw = dp[i][j];
                    pos = {i,j};
                }
            }
        }
        if(pos.first == 0 && pos.second == 0){
            cout << endl;
            continue;
        }

        vector<char> a; 
        auto cur = pos; 
        while (cur.first != 0 && cur.second != 0) {
            int i = cur.first;
            int j = cur.second;
            pair<int,int> prev = f[i][j];
            if(prev == make_pair(i-1,j-1))
                a.pb(s[i-1]);

            cur = prev;
        }

        reverse(all(a));    
        
        for(auto &i: a) cout << i;
        cout << endl;



    }

    return 0;
}
