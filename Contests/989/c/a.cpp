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

int dx[] = {0 , 1, 0, -1};
int dy[] = {1 , 0, -1, 0};


bool dfs(int x, int y, vector<vector<char>> &a, vector<vector<int>> &marked, vector<vector<bool>> &trap){
    if(marked[x][y] == 1){
        return trap[x][y];
    }
    if(marked[x][y] == 2){
        return 1;
    }
  
    marked[x][y] = 2;
    if(a[x][y] == '?'){
         
        bool asw = 0;
        for(int i = 0; i < 4; i++){
            int l = dx[i] + x, k = dy[i] + y; 
            if(l < 0 || l >= a.size()) continue;
            if(k < 0 || k >= a[0].size()) continue;
            bool f = dfs(l, k, a, marked, trap); 
            asw |= f;
        } 
        trap[x][y] = asw;
    }

    else{
        if(a[x][y] == 'U'){
            if(x-1 < 0) trap[x][y] = 0;
            else trap[x][y] = dfs(x-1, y, a,marked, trap);
        }
        if(a[x][y] == 'D'){
            if(x+1 >= a.size()) trap[x][y] = 0;
            else trap[x][y] = dfs(x+1, y, a,marked, trap);
        }
        if(a[x][y] == 'L'){
            if(y-1 < 0) trap[x][y] = 0;
            else trap[x][y] = dfs(x, y-1, a,marked, trap);
        }
        if(a[x][y] == 'R'){
            if(y+1 >= a[0].size()) trap[x][y] = 0;
            else trap[x][y] = dfs(x, y+1, a,marked, trap);
        }
    }
        
    marked[x][y] = 1;
    return trap[x][y];
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        int n, m;
        cin >> n >> m;
    

            
        vector<vector<char>> a(n, vector<char>(m,0));
        vector<vector<int>> marked(n, vector<int>(m,0));
        vector<vector<bool>> trap(n, vector<bool>(m,0));


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
 

        int asw = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(i, j, a, marked, trap); 
                if(trap[i][j]) asw++; 
            }
        }

        

        cout << asw << endl;



    }




    return 0;
}
