#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

const ll N = 1e5+1;
vector<bool> sv(N,1);
vector<int> primes;
int psize;
void sieve(){
    for(ll i = 2; i*i < N; i++){
        if(sv[i]) for(ll j = i*i; j < N; j+=i)
            sv[j] = 0;
    }

    for(int i = 2; i < N; i++){
        if(sv[i]) primes.pb(i);
    } 
    psize = primes.size();
}

void factor(int x, vector<int> &p){
    for(int i = 0; primes[i] * primes[i] <= x && i < psize; i++){
        const int k = primes[i]; 
        if(x % k == 0){
            while (x % k == 0) x /= k;
            p.pb(k);
        }
    }
    if(x != 1) p.pb(x);
}




int main (int argc, char *argv[]){
    sieve(); 

    /*
    vector<ll> l;
    factor(7817670, l);
    for(auto &i: l) cout << i << endl;
    */

    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<int> a(n);
    vector<pair<int,int>> b(n); 

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int k = 0; k < n; k++){
        b[k].first = -1;
        b[k].second = -1;

        vector<int> p; 
        factor(a[k], p);
        if(p.size() < 2) continue;            

        int x = p[0];
        //int y = a[k]/p[0]; 
        //y/=p[i],
        for(int i = 1; i < p.size(); x*=p[i], i++){
            if(gcd(p[i] + x, a[k]) == 1){
                b[k].first = x;
                b[k].second = p[i];
                break; 
            } 
        }
    }


    for(int i = 0; i < n; i++){
        cout << b[i].first << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << b[i].second << " ";
    }
    cout << endl;



    return 0;
}
