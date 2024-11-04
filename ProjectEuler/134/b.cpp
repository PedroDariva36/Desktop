#include <bits/stdc++.h>
#include <cmath>
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

const ll N = 1e9+1;
const ll GAP_MAGIC = 1550;
vector<bool> sv(sqrt(N) + 1,true);
vector<ll> primes;


ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void sieve(){
    sv[0] = 0;
    sv[1] = 0;
    for(ll i = 2; i*i <= sqrt(N); i++)
        if(sv[i]) for(ll j = i*i; j <= sqrt(N); j+=i)
            sv[j] = 0;
    for(int i = 0; i <= sv.size(); i++) if(sv[i]) primes.pb(i);
}

ull solve(ll l, ll r){

    vector<bool> isPrime(r+GAP_MAGIC - l + 1, true);
    vector<ll> locals; 
    for (auto &i : primes)
    for (ll j = max(i * i, (l + i - 1) / i * i); j <= r+GAP_MAGIC; j += i)
        isPrime[j - l] = false;
    if (l == 1)  isPrime[0] = false;

    for(ll i = 0; i < isPrime.size(); i++){
        if(isPrime[i]) {
            locals.pb(i+l);
            if(i > r-l) break; 
        } 
    }


    ull sum = 0;
    // (k*10^md + x)%y = y%y;
    //(k*10^md)%y + x%y = y%y;
    //(k*10^md) = (y-x)%y;
    //k % y = (inverseMod(10^md) * (y-x) %y

    //To get the Modular inverse of  x mod y
    //You just do binpow(x,y-2,y);

    for(int i = 0; i < (int)locals.size()-1; i++){
        ll x = locals[i];
        ll y = locals[i+1];
        ll l = 10;
              
        while(l < x) l*=10;

        ll k = (
            (y-x)*1ll*binpow(l, y-2, y) ) % y;
        sum = ( sum + 1ll*k*l+x)%(ll)(1e9+7);
    }

    return sum;
}


int main (int argc, char *argv[]){
    sieve(); 
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        ll l, r;
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }

    return 0;
}
