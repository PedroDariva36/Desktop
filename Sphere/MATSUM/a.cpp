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
#pragma GCC optimize("Ofast")

const int N = 1030;
int t[N+N][N+N];
int n;


void build (){
    for(int i = n; i < n+n; i++)
        for (int j = n-1; j > 0; j--)
            t[i][j] = t[i][j << 1] + t[i][j<<1|1];
    for (int i = 1; i < n+n; i++) {
        for (int j = n-1; j > 0; j--)
            t[j][i] = t[j<<1][i] + t[j<<1|1][i];
    }
}

void update(int x,int y, ll v){
    t[x+n][y+n] = v; 
    for(int i = x + n; i > 0; i >>= 1){
        for(int j = y + n; j > 1; j >>= 1){
            t[i][j>>1] = t[i][j] + t[i][j^1];
        }
        if(i > 1) t[i>>1][y+n] = t[i][y+n] + t[i^1][y+n];
    }
    
}

long query(int l, int u, int r, int d){
    long asw = 0;
    for (l+=n, r+=n; l <= r; ++l >>= 1, --r >>= 1) {
        for (int i = u+n, j = d+n; i <= j; ++i >>= 1, --j >>= 1) {
            if (l&1){
                if(i&1) asw += t[l][i];
                if(!(j&1)) asw += t[l][j];
            }
            if (!(r&1)){
                if(i&1)  asw += t[r][i];
                if(!(j&1)) asw += t[r][j];
            }
        }
    }
    return asw;
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0); 
    int tt = 1;
    cin >> tt;
    while(tt--){
        cin >> n;
        build();
    
        string op;
        while(cin >> op){
            if(op == "SUM"){
                int a, b, x, y; 
                cin >> a >> b >> x >> y;
                cout << query(a,b,x,y) << endl; 
                continue; 
            }

            if(op == "SET"){
                int x, y, v;
                cin >> x >> y >> v;
                update(x, y, v);            
                continue;    
            }
            break;
        }


        /*
        for(int i = 0; i < n+n; i++){
            for(int j = 0; j < n+n; j++){
                cout << t[i][j] << " ";
            }
            cout << endl;
        }

        */
    
    }

    return 0;
}
