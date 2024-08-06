#include <bits/stdc++.h>
#include <iomanip>
#define _USE_MATH_DEFINES
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        double n, l;
        double r, R, h, H, v2, V, Hf;
        double o = 0;
        
        cin >> n >> l;
        cin >> r >> R >> h; 
        

        if(r != R){
            o = atan((h/(R-r)));
            H = tan(o)*r;
            v2 = (H*H*H * M_PI)/(3*tan(o)*tan(o));
            V = l/n + v2;
            Hf = cbrt((3*V*tan(o)*tan(o))/M_PI);
            Hf -= H;
        }
        else{
            V = l/n; 
            Hf = V/(M_PI*r*r); 
        }
        
        cout << fixed << setprecision(2) << Hf << endl;
    }
    return 0;
}
