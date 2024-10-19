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

const ll N = 1e5;
vector<vector<int>> sv(N+1);
void sieve(){
    for(ll i = 2; i <= N; i++){
        if(sv[i].empty()) for(ll j = i; j <= N; j+= i){
            sv[j].pb(i); 
        }
    }
    /*
    for(int i = 2; i <= N; i++){
        for(auto &j : sv[i])  cout << j << " ";
        cout << endl;
    }
    */
}


int main (int argc, char *argv[]){
    sieve(); 
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    //cin >> tt;
    while(tt--){
        int n, q;
        cin >> n >> q;
            
        set<int> s;
        map<int,int> k;

        while (q--) {
            int x; char op;
            cin >> op >> x; 
        
            if(op == '+'){
                if(s.count(x)){
                    cout << "Already on" << endl;
                    continue;
                }
    
                int f = 0;
                for(auto &i: sv[x]){
                    if(k[i] != 0){
                        f = k[i];    
                        break; 
                    }
                } 
               
                if(f){
                    cout << "Conflict with " << f << endl;
                    continue; 
                }
                else{
                    s.insert(x);
                    for(auto &i: sv[x]){
                        k[i] = x; 
                    }
                    cout << "Success" << endl;
                }
            }

            else{
                if(!s.count(x)){
                    cout << "Already off" << endl;
                    continue;
                }
                
                

                s.erase(x);
                for(auto &i: sv[x]){
                    k[i] = 0; 
                }
                cout << "Success" << endl;
            }
        }
    }

    return 0;
}
