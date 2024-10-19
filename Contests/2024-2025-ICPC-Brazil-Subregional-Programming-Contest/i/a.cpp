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

const int N = 1e6+1;
const ll mod = 1e9+7;
vector<int> f(N);
vector<ll> p2(N);
vector<vector<int>> pf(N);

void sieve(){
    p2[0] = 1;
    for(int i = 1; i < N; i++) p2[i] = ((ll)p2[i-1]<<1)%mod;

    for(int i = 2; i < N; i++){
        for(int j = i+i; j < N; j+=i){
            f[i] += f[j];
        }
    } 
    
    for(int i = 2; i < N; i++)
        if(pf[i].empty()) 
            for(int j = i; j < N; j+=i)
                pf[j].pb(i);
}




int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
 //   cin >> tt;
    while(tt--){
        int n, aux, q = 0; 
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> aux;
            f[aux]++; 
        }
        f[1] = n;
        sieve();

        cin >> q;
        while (q--) {
            cin >> aux; 
            /*        
            if(aux == 1){
                cout << p2[n] << endl;
                continue;
            }
            */

            int sum = 0;
            for (int msk = 1; msk < (1 << pf[aux].size()); ++msk) {
                int mult = 1, b = 0;

                for (int i = 0; i < (int)pf[aux].size(); ++i)
                    if (msk & (1<<i)) {
                        ++b;
                        mult *= pf[aux][i];
                    }

                int c = f[mult];
                sum += (b % 2 == 1? c : -c);
                
            }
            cout << p2[n-sum] << endl;
        } 


    }

    return 0;
}
