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





int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<ll>a(n), b(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }

    sort(all(b));
    ll asw = ((1 + b[0])>>1) + ((1 + b[1]) >> 1);

    for (int i = 0; i < n-1; i++) { 
        ll sum = 0; 
        ll sa = a[i]; 
        ll sb = a[i+1];
        if(sa < sb) swap(sa,sb);

        ll dif = min(sa-sb, (sa+1)/2); 
        sum += dif; 
        sa -= dif*2; 
        sb -= dif; 

        if(sa > 0 && sb > 0) sum += (sa+1 + sb+1)/3;
        asw = min(asw,sum);



    }
    
    for (int i = 0; i < n-2; i++) { 
        ll sa = a[i];
        ll sb = a[i+2];
        if(sa < sb) swap(sa,sb); 
        
        ll sum = (sa - sb + 1)/2;
        


        asw = min(asw,sum + sb);
    } 
    cout << asw << endl;

    return 0;
}
