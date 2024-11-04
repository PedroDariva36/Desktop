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

using namespace std;
const int N = 1010*2;
int t[N+N][N+N];
int n;


void build (){
    for(int i = n; i < n+n; i++)
        for (int j = n-1; j > 0; j--) 
            t[i][j] = gcd(t[i][j << 1] , t[i][j<<1|1]);
    for (int i = 1; i < n+n; i++) {
        for (int j = n-1; j > 0; j--) 
            t[j][i] = gcd(t[j<<1][i] , t[j<<1|1][i]);
    } 
}

void modify(int a , int b, long c){
    t[a+n][b+n] = c; 
    for(int i = a + n; a > 1; a >>= 1){ 
        for(int j = b + n; j > 1; j >>= 1) 
            t[a][b >> 1] = gcd(t[a][b],t[a][b^1]);
        t[a >> 1][b] = gcd(t[a][b],t[a^1][b]);
    }
}



long query(int l, int u, int r, int d){
    long asw = 0;
    for (l+=n, r+=n; l <= r; ++l >>= 1, --r >>= 1) {
        for (int i = u+n, j = d+n; i <= j; ++i >>= 1, --j >>= 1) {
            if (l&1){
                if(i&1) asw = gcd(asw, t[l][i]);
                if(!(j&1)) asw = gcd(asw, t[l][j]);
            }
            if (!(r&1)){
                if(i&1)  asw = gcd(asw, t[r][i]);
                if(!(j&1)) asw = gcd(asw, t[r][j]);
            } 
        }
    } 
    return asw; 
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    n = 1010;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t[i+n][j+n] = 0;
        }
    }

    build();



    int tt = 1;
    cin >> tt;
    while(tt--){
        string s;
        int a, b, c; 
        cin >> s >> a >> b >> c;
        
        if(s[0] == 'S') modify(a + 501, b+501, c);
        else cout <<  query(0, 0, a, b) << endl;;
    }

    return 0;
}
