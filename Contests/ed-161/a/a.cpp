#include <bits/stdc++.h>
#define ll long long

using namespace std;



int main (int argc, char *argv[]){
    int t, n;
    cin >> t;    

    while (t--) {
        cin >> n;
        string a , b ,c;
        cin >> a >> b >> c; 
        bool z = false;
        int x = 0;
        for (int i = 0; i < n; i++) {
            if(a[i] == b[i] && b[i] == c[i]){
                continue;
            }
            if(b[i] == c[i] && c[i] != a[i]){
                continue;
            }
            if(a[i] == c[i] && c[i] != b[i]){
                continue; 
            }
            x++; 
        }
        
        if (z){
            cout << "NO" << endl;
            continue;
        }
        
        if(x > 0) cout << "YES" << endl;
        else cout << "NO" << endl;

    }


    return 0;
}
