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

const ll MAXN = 2e5;
vector<ll> t(4*MAXN,0);
vector<ll> lazy(4*MAXN,0);


void build(vector<ll> a, ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2 + 1]);
    }
}

void push(ll v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll addend, ll x, ll y) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
       if(t[v] >= x && t[v] <= y) t[v] += addend;
       if(lazy[v] >= x && lazy[v] <= y) lazy[v] += addend;
    } else {
        push(v);
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend,x,y);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend,x,y);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return -1e12;
    if (l == tl && tr == r)
        return t[v];
    push(v);
    ll tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}




int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n); 
        
        for(auto &i: a) {
            cin >> i;
        }
    
        build(a, 1, 0, n-1);
   

        while (m--) {
            char op; 
            int x,y; 
            cin >> op >> x >> y; 

            update(1, 0, n-1, 0, n-1,(op == '-'? -1:1),x,y); //);
            cout << query(1,0, n-1, 0, n-1) << " ";
            
        }
        cout << endl;
        


    }
    return 0;
}
