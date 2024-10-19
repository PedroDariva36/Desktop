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
    int n, k = 0;
    cin >> n;
    
    vector<int> a(n);
    for(auto &i: a) {
        cin >> i;
        k += i;
    }

    if(k%2 != 0){
        cout << "-1" << endl;
        return 0;
    }
    k>>=1;
    
    vector<vector<bool>> memo(n + 1, vector<bool>(k+1,0)); 
    for (int i = 1; i <= k; i++) memo[0][i] = false; 
    for (int i = 0; i <= n; i++) memo[i][0] = true; 
  
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= k; j++) { 
            memo[i][j] = memo[i - 1][j]; 
            if (a[i - 1] <= j) 
                memo[i][j] = memo[i][j] | memo[i - 1][j - a[i - 1]]; 
        } 
    } 

//    cout << k << endl;

    if(!memo[n][k]){
        cout << "-1" << endl;
        return 0;
    }

    vector<int> f, g; 
    { 
        int i = n; 
        int j = k; 

        while (i > 0 && j >= 0) { 
            if (memo[i - 1][j]) g.push_back(a[--i]);  
            else if (memo[i - 1][j - a[i - 1]]) { 
                j -= a[--i]; 
                f.pb(a[i]); 
            } 
        } 
    }


    int j = 0, l = 0;
    ll sum = 0; 
    for(int i = 0; i < n; i++){
        if(sum <= 0){
            sum += f[l];
            cout << f[l] << " ";
            l++;
        } 
        else {
            sum -= g[j];
            cout << g[j] << " "; 
            j++; 
        }    
    }
    
    cout << endl;

    return 0;
}
