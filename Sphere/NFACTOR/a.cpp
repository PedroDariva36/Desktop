#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

const ll N = 1e6;
vector<vector<int>> primes(N+1);

vector<vector<int>> prefix(N+1,vector<int>(11,0));


void sieve(){
    for(int i = 2; i <= N; i++){
        if(primes[i].empty()) for(int j = i; j <= N; j+=i){
            primes[j].pb(i); 
        }
    }

    vector<int> sum(11,0);
    
    for(int i = 0; i <= N; i++){
        sum[primes[i].size()]++;
        prefix[i] = sum;
    } 
}

int sum(int x, int y, int n){
    return(prefix[y][n] - prefix[x][n] + (primes[x].size() == n? 1:0)); 
}

int main (int argc, char *argv[]){
    sieve();
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        int x, y, n; 
        cin >> x >> y >> n;
        cout << sum(x,y,n) << endl;
    }

    return 0;
}