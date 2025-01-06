#include <bits/stdc++.h>
#include <csignal>
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
        int n;
        string s;
        cin >> s;
        n  = s.size();
        ll sum = 0;
           
        int two = 0;
        int three = 0;
        int k;    

        for(int i = 0; i < n; i++){
            int k = s[i] - '0';
        
            if(k == 2) two++;
            if(k == 3) three++;
        
            sum += k;
            sum %= 9;
        }   

        if(sum == 0){
            cout << "YES" << endl;
            continue;
        } 
        
        bool f = 0;
        for(int i = 0; i <= min(two, 20); i++){
            for(int j = 0; j <= min(three, 20); j++){
                if(((sum + i*2 + (j*6))%9 + 9) % 9 == 0) f = 1; 
            }
        }



        cout << (!f? "NO":"YES") << endl; 


        






    }

    return 0;
}
