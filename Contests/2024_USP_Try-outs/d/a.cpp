#include <bits/stdc++.h>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <iomanip>
#include <ios>
#include <vector>
struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);}};
template<typename T, typename comp_function = std::less<T>> using indexed_set = class __gnu_pbds::tree<T, __gnu_pbds::null_type, comp_function, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<typename K, typename V> using hash_map = std::unordered_map<K, V, custom_hash>;
template<typename T> using hash_set = std::unordered_set<T, custom_hash>;
#define ll  long long
#define ull unsigned long long
#define double long double
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;




double edist(double a, double b, double c, double x, double y, double z){
    return sqrt((a-x)*(a-x) + (b-y)*(b-y) + (c-z)*(c-z));
}

bool h;
ll x,y,z;
bool solve(double r, vector<ll> &dx, vector<ll> &dy, vector<ll> &dz, double a, double b, double c, double rt){
    int f = 0;
    
    for (int i = 0; i < 8; i++) {
        double x = (dx[i] > r? dx[i]-r: r);
        double y = (dy[i] > r? dy[i]-r: r);
        double z = (dz[i] > r? dz[i]-r: r);



        //cout<< setprecision(15)<< x << " " << y << " " << z << endl;
        //cout << setprecision(15) << edist(a,b,c,x,y,z) << endl;

        if(edist(a,b,c,x,y,z) - rt >= r) f = 1;

        

    }
    
    return f;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    double a,b,c;
    double rt;
    
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    cin >> rt;

    vector<ll>  dx = {x,0,x,0,x,0,x,0}, 
                dy = {y,0,0,y,y,0,0,y}, 
                dz = {z,0,0,0,0,z,z,z};   

    double l = 0.0;
    double r = min(x, min(y, z));
    

    int q = 100;
    while (q--) {
        double mid = (l+r)/2;
        //cout << mid << endl;
        bool k = solve(mid,dx,dy,dz,a,b,c,rt); 
        if(k)
            l = mid;
        else 
            r = mid;
    }    


    cout << setprecision(15) << fixed << l << endl;
    






    return 0;
}
