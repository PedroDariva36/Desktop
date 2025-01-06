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

void xorString(string &a, string &b){
    for(int i = 0; i < a.size(); i++){
        int x = a[i] - '0';
        int y = b[i] - '0';
        a[i] = (x^y) + '0';
    }

}


int main (int argc, char *argv[]){
    //cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        string s; 
        cin >> s;
        cout << 1 << " " << s.size() << " ";   
        int n = s.size(); 
        string b;

        bool f = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') f= 1;
        }
        
        if(!f){
            cout << 1 << " " << 1 << endl;
            continue; 
        }
        int t = 1; 
        vector<pair<string,int>> asw; 
        for(int k = 1; k < n; k++){
            if(s[k] == '1') continue;
            t = n-k;
            vector<int> pos;

            for(int i = 0; i < n; i++){
                if(i+t > n) break; 
                if(s[i] == '1') pos.pb(i);
            } 
           

            if(pos.empty()) continue;

            for(auto &i : pos){
                string aux;
                for(int j = i; j < i+t; j++) aux.pb(s[j]);
                asw.push_back({aux,i});
            } 
            break; 
        }
        
        string aux;
        for(int i = n-t; i < n; i++){
            aux.pb(s[i]);
        }

        for(auto &i: asw){
            xorString(i.first, aux);           
        }

        sort(rall(asw));

//        for(auto &i: asw) cout << i.first << " " << i.second << endl;

        cout << asw.front().second+1 << " " << asw.front().second+t << endl;;

    }

    return 0;
}
