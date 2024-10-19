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


void setBit(int x, int val, vector<int> &bit){
    for (; x < bit.size(); x = x|(x+1))

        bit[x] += val;
}   


ll getBit(int x,  vector<int> &bit){
    ll sum = 0;
    for (;x >= 0; x = (x & (x + 1)) - 1)
        sum += bit[x];
    return sum;
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> bit(n*m,0);
    vector<int> a(n*m,0);
        

    char aux; 
    ll c = 0;  
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> aux; 
            if(aux == '*'){
                a[i + j*n] = 1;
                setBit(i + j*n, 1 ,bit);     
                c++; 
            }
        }
    }

    ll x, y;
    ll pos;
    while (q--) {
        cin >> x >> y; 
        x--; y--;
        pos = x + y*n;


        ll val = a[pos];
        setBit(pos, (val? -1:1), bit);
        a[pos] =! a[pos];
        c += (val? -1 : 1);

        cout << c - getBit(c-1, bit)  << endl;
    }


    return 0;
}
