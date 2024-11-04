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

const ll MOD = 1e9+7;
const int N = 5e5+1;
vector<bool> sv(N, 1);
vector<ll> primes;
void sieve(){
    for(int i = 2; i*i < N; i++){
        if(sv[i]) for(int j = i*i; j < N; j+=i)
            sv[j] = 0; 
    }
    for(int i = 2; i < N; i++){
        if(sv[i]) primes.pb(i);
    }
}

int multiplicity_factorial(int n, int p) {
    int count = 0;
    do {
        n /= p;
        count += n;
    } while (n);
    return count;
}


ll calcTau(ll n){
    ll sum = 1; 
    ll k = 0;
    for(auto &i: primes){
        if(n < i) break;
        k = (multiplicity_factorial(n, i) + 1); 
        sum *= (k? k: 1);
        sum %= MOD;
    }    
    return sum;
}



int main (int argc, char *argv[]){
    sieve(); 
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        ll n;
        cin >> n;
        cout << calcTau(n) << endl;; 
    }

    return 0;
}
