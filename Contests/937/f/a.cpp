#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b ,c;
        cin >> a  >> b >> c;
        
        if ((c != a+1)) {
            cout << -1 << endl;
            continue;
        }

        int h = (a? (32 - __builtin_clz(a)) : 0);
        int extra = (1 << h) - (a+1); 
        b -= min(b, extra); 
        cout << h + (b + c-1)/c << endl;
        

        

    }

    return 0;
}
