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

    
int calcMex(vector<int> &a){
    int mex = 0;
    vector<bool> aux(a.size()+1); 
    for(auto &i: a){
        aux[i] = 1;
        while (aux[mex]) {
            mex++;
        }
    }
    return mex;
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        int n, m;
        cin >> n >> m;


        if(m == 1){
            cout << 0 << endl;
            for(int i = 0; i < n; i++){
                cout << 0 << endl;
            } 
            cout << endl; 
            continue; 
        }

        if(m == 2){
            cout << 2 << endl;
            for(int j = 0; j < n; j++){
                for(int i = 0; i < m; i++)
                    cout << i << " ";
                cout << endl; 
            }
            continue;
        }
        
        if(n == 1){
            cout << 2 << endl;
            for(int i = 0; i < m; i++){
                cout << i << " ";
            }
            cout << endl;
            continue;
        }


        vector<vector<int>> a(n, vector<int>(m));    
        vector<int> mex(m);
        


        for(int i = 0; i < n; i++){
            if(i < m-1) for(int j = 0; j < m; j++){
                a[i][j] = (i+j)%m;
            }
            else for(int j = 0; j < m; j++){
                a[i][j] = j;
            }

        }
        
        for(int j = 0; j < m; j++){
            vector<bool> aux(max(n,m)+1);
            int mx = 0;
            for(int i = 0; i < n; i++){
                aux[a[i][j]] = 1;
                while (aux[mx]) {
                    mx++;
                }
            }
            mex[j] = mx;
        }
        
        cout << calcMex(mex) << endl;
        for(auto &i: a){
            for(auto &j: i)
                cout << j << " ";
            cout << endl; 
        } 


        


    }

    return 0;
}
