#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <iomanip>
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

typedef struct Point{
    int x, y;  
}p;


double ed(p A, p B){
    return hypot(A.x - B.x, A.y - B.y);
}

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
         
        p P, A, B, O; 
        
        O.x = 0;
        O.y = 0;
    


        cin >> P.x >> P.y;
        cin >> A.x >> A.y;
        cin >> B.x >> B.y;

        double edAB = ed(A,B); 
        double W = edAB/2; 
        double edAP = ed(A,P); 
        double edAO = ed(A,O); 
        double edBP = ed(B,P); 
        double edBO = ed(B,O);

        if(W > max(edAP, edAO) || W > max(edBP, edBO)){
            cout << setprecision(10) << fixed << min(max(edAP, edAO),max(edBP, edBO)) << endl;;
            continue; 
        }
  
        if(W < max(edAP, edAO) && W > min(edAP, edAO) || W < max(edBP, edBO) && W > min(edBP, edBO)){
            
            if(edAP > W && edAO < W && edBP < W && edBO > W || edAP < W && edAO > W && edBP > W && edBO < W){ 
                cout << setprecision(10) << fixed << W << endl;
            } 
            else{
                cout << setprecision(10) << fixed << max(min(edAO, edBO),min(edBP, edAP)) << endl;;
            } 

            continue;
        }

        cout << setprecision(10) << fixed << max(min(edAO, edBO),min(edBP, edAP)) << endl;;

    }

    return 0;
}
