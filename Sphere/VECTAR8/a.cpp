#include <algorithm>
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


const ll N = 1e6+1;
vector<bool> prime(N, true);
vector<bool> x(N,0);
vector<int> pref(N,0);

void sieve(){
    prime[0] = false;
    prime[1] = false;

    for(ll i = 2; i*i <= N; i++){
        if(prime[i]){
            for(ll j = i*i; j <= N; j+= i)
                prime[j]=0;
        }
    }
    for(ll i = 2; i < N; i++){
        if(!prime[i]) continue;
        vector<int> l;
        ll k = i;
        bool f = 1;
        while (k) {
            ll aux = k%10;
            l.pb(aux); 
            k/=10;
        }
        
        reverse(all(l));
        for(auto &c: l) if(c == 0) f = 0;       
        if(f){ 
            ll aux;
            for(int c = 1; c < l.size(); c++){
                aux = 0; 
                for(int j = c; j < l.size(); j++){
                    aux += l[j] * pow(10,(l.size()-j-1)); 
                } 
                if(!prime[aux]) f = 0;
            }
        }
        x[i] = f;
    }
    

    ll sum = 0; 
    for(ll i = 0; i < N; i++){
        sum += x[i];
        pref[i] = sum;
    }
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    sieve(); 
    int tt = 0;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        cout << pref[n] << endl;
    }
    return 0;
}
