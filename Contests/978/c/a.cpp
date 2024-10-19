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

const int N = 1e5+1;
vector<array<char, 2>> a(N);
vector<vector<int>> dp(N, vector<int>(3,-1));
int n;



int conv(char c){
    if(c == 'A') return 1;
    else return 0;
}

vector<array<int,2>> d = {
    {0, 0},
    {0,-1},
    {-1,0} 
};
ll solve(int x , int y){
    if(x >= n) return 0;
    if(dp[x][y] != -1) return dp[x][y];


    ll g = conv(a[x][0]) + conv(a[x][1]);
    ll k = 0, l = 0; 
    ll asw0 = 0;
    ll asw1 = 0;
    ll asw2 = 0;


    if(n - x > 2){
        for(int i = x + d[y][0]; i < x+3 + d[y][0]; i++) 
            k += conv(a[i][0]);      
        for(int i = x + d[y][1]; i < x+3 + d[y][1]; i++) 
            l += conv(a[i][1]);      
        asw0 = solve(x+3, y) + (k > 1? 1: 0) + (l > 1? 1: 0);       
    }
    

    if(y == 0){
        asw1 = solve(x+2, 1) + (g + conv(a[x+1][0]) > 1? 1: 0);          
        asw2 = solve(x+2, 2) + (g + conv(a[x+1][1]) > 1? 1: 0);         
    }  

    if(y == 1)
        asw1 = solve(x+1, 0) + (g + conv(a[x-1][1]) > 1? 1: 0);          

    if(y == 2)
        asw2 = solve(x+1, 0) + (g + conv(a[x-1][0]) > 1? 1: 0);         
    
    return dp[x][y] = max(asw1,max(asw2,asw0));

}



int main (int argc, char *argv[]){
//    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i][0];
            dp[i] = {-1,-1,-1};
        }
        for(int i = 0; i < n; i++) cin >> a[i][1];

        cout << solve(0, 0) << endl;;

    }

    return 0;
}
