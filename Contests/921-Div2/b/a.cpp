#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <ios>
#define ll long long
#define pii pair<int, int>
using namespace std;


int t;
int main (int argc, char *argv[]){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    cin >> t;
    while (t--) {
        long n, m;
        long gd = 1;
        cin >> n >> m;
        for (long d = sqrt(n); d > 0 ; d--) 
            if(n%d == 0) {
                if(d <= n/m) gd = max(gd, d);
                if(m <= d) gd = max(gd, n/d);
            }
        cout << gd << endl;
    }    

    return 0;
}
