#include <bits/stdc++.h>
#include <cstdlib>
#define ll long long
using namespace std;

int main (int argc, char *argv[]){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int t,n;
    bool aux;

    cin >> t;
    while (t--) {
        cin >> n;
        int c0 = 0, c1 = 0;
        
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if (b[i] - '0') c1++;
                else c0++;
            }
        }


        cout << max(c1,c0) << endl;

    }



    return 0;
}
