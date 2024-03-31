#include <bits/stdc++.h>
#include <cmath>
#define ll long long

using namespace std;



int main (int argc, char *argv[]){
    

    ll t,a ,b ,c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        double x = abs(a-b);
        
        x = (x/2)/c;
        x = ceil(x);
        
        cout << x << endl;
        
     
    }


    return 0;
}
