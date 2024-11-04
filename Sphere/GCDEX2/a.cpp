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

const ull N = 1e7+1;
vector<ull> pref(N);
vector<ull> phi(N);
map<ull,ull> memo;

void sieve(){
    for(int i = 0; i < N; i++) phi[i] = i;         
    for(int i = 2; i < N; i++)
        if(phi[i] == i) for(ull j = i; j < N; j+=i)
            phi[j] -= phi[j]/i;

    ull sum = 0;
    for(int i = 0; i < N; i++){
        sum += phi[i];
        pref[i] = sum;
    
    }
}


__uint128_t gauss(ull n){
    __uint128_t x = (__uint128_t )n * (n+1);
    x /= 2;
    return x;
}

ull sumPhi(ull n){
    if(n < N) return pref[n]; 
    if(memo.count(n)) return memo[n]; 
    __uint128_t sum = gauss(n);

    ull k = sqrt(n);
    for(ll i = 2; i <= k; i++) 
        sum -= sumPhi(n/i);

    for(ull i = 1; i < n/k; i++) 
        sum -= (n/i - n/(i+1)) * pref[i];

    memo[n] = sum;
    return sum;
}


ull gcdSum(ull n){
    ull sum = 0;
    ull k = sqrt(n); 

    for(ull i = 1; i <= k; i++){
        sum += i * (ull)sumPhi(n/i);
        sum += phi[i] * (ull)gauss(n/i);
    }
    sum = sum - (ull)gauss(n);
    sum = sum - (ull)gauss(k) * sumPhi(k);     
    
    return sum;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0); 
    sieve(); 
    int t;
    ull n;
    cin >> t; 
    while(t--){
        cin >> n;
        cout << gcdSum(n)  << endl;
    }

    return 0;
}
