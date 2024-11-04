#include <algorithm>
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
    int tt = 1;
    cin >> tt;
    while(tt--){
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        vector<char> s(n);
        vector<ll> mn(n, 1e9), mx(n,-1);
        ll aux = -1;


        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++) 
            cin >> s[i];


        for(int i = 0; i < n; i++){
            aux = max(a[i],aux);
            mx[i] = aux;
        }
        aux = 1e9; 
        for(int i = n-1; i>= 0; i--){
            aux = min(a[i],aux);
            mn[i] = aux; 
        }

        

        
        int block = 0;
        for (int i = 0; i < n-1; i++){
            if(s[i] == 'L' && s[i+1] == 'R') 
                if(mx[i] > mn[i+1]) block++; 
        }   
    
        while (q--) {
        
            int x = 0;     
            cin >> x;
            x--; 
        
            s[x] ^= 'L' ^ 'R';


            if(s[x] == 'R'){
                if(s[x+1] == 'R') 
                    if(mx[x] > mn[x+1]) block--;
                if(s[x-1] == 'L') 
                    if(mx[x-1] > mn[x]) block++;
            } 
            else{
                if(s[x+1] == 'R') 
                    if(mx[x] > mn[x+1])  block++;
                if(s[x-1] == 'L') 
                    if(mx[x-1] > mn[x])  block--; 
            } 

            cout << (block != 0? "NO":"YES") << endl;;
        } 










    }



    return 0;
}
