#include <bits/stdc++.h>
#include <ios>
#define ll long long
using namespace std;



int main (int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        long n, m;
        cin >> n >> m;
        
        if (n == 1 && m == 1) {
            cout << "NO" << endl;
            continue;
        }
        
        if(n%2 != 0 & m%2 != 0){
            cout << "NO" << endl;
            continue;
        }
    

        if (max(n,m) == 2*min(n,m)) {
            if(n%2 == 0 & m%2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }
        
        cout << "YES" << endl;


    }
    return 0;
}
