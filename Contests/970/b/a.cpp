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

map<int,int> roots;
const int N = 1e6+1;
void sieve(){
    for(int i = 1; i*i <= N; i++){
        roots[i*i] = i;
    }
}


int main (int argc, char *argv[]){
    sieve(); 
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        char aux;
        cin >> n;
        vector<int> a(n);
        for(auto &i: a) {
            cin >> aux; 
            i = aux - '0';
        }



        int k = 0;
        if(roots.count(n)) k = roots[n];       
        if(k == 0){ 
            cout << "No" << endl;
            continue;
        }
        bool f = 1;
        
        vector<vector<int>> m(k,vector<int>(k));
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++)
                m[i][j] = a[(i)*k + j];
        } 
        /*
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++)
                cout << m[i][j] << " ";
            cout << endl;
        } 
        */

        for(int i = 0; i < k; i++){
            if(m[i][k-1] == 0) f = 0;
            if(m[i][0] == 0) f = 0;
        } 
        
        for(int i = 0; i < k; i++){
            if(m[k-1][i] == 0) f = 0;
            if(m[0][i] == 0) f = 0;
        } 

        for(int i = 1; i < k-1; i++){
            for(int j = 1; j < k-1; j++)
                if(m[i][j] == 1) f = 0;
        }



        cout << (f? "Yes":"No") << endl;
    }
    return 0;
}