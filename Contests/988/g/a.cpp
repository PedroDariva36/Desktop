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

const int N = 1e6;
vector<int> primes;
vector<bool> sv(N+1, 1);

void sieve(){
    for(int i = 2; i * i <= N; i++){
       if(sv[i]) for(int j = i*i; j <= N; j+=i)
            sv[j] = 0;
    }
    for(int i = 2; i <= N; i++)
       if(sv[i]) primes.pb(i);
}


void factor(int x, vector<int> &d){
    for(int i = 0; primes[i]*primes[i] <= x && i < primes.size(); i++){
        if(x%primes[i] == 0){
            d.pb(primes[i]);
            while (x%primes[i] == 0) x /= primes[i];    
        }
    }
    if(x != 1) d.pb(x);
}

ll a[200001];
ll divisors[N+1];
const ll mod = 998244353;

int main (int argc, char *argv[]){
    sieve();
    a[1] = 1;
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    while(tt--){
        ll n,aux;
        cin >> n;
        
        for(int i = 1; i <= n; i++){
            cin >> aux; 
            vector<int> p,d;        
            factor(aux,p);
        
            for(int j = 1; j < (1<<p.size()); j++){
                ll c = 0, mul = 1;
    
                for(int k = 0; k < p.size(); k++)
                    if(j>>k & 1)
                        c++, mul*=p[k];
                d.pb(mul);

                if(c%2 == 0){
                    a[i] -= divisors[mul];
                    a[i] %= mod; 
                }
                else{
                    a[i] += divisors[mul];
                    a[i] %= mod;
                }
                
                a[i] = (a[i] % mod + mod)%mod;

            }
            for(auto &j: d){
                divisors[j] += a[i];
                divisors[j] %= mod;
            } 
        }  

        cout << a[n] << endl;

    }

    return 0;
}
