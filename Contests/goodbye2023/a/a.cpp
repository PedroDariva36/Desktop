#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main (int argc, char *argv[]){
    
    int t;
    cin >> t;
    while (t--) {
        int n,k,aux;
        cin >> n >> k;
        
        ll p = 1;
        for (int i = 0;i < n; i++) {
            cin >> aux; 
            p *= aux; 
        }
        if (2023 % p != 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES"<<endl;
        cout << 2023/p << " ";
        for (int i = 1; i < k; i++)
            cout << 1 << " "; 
        cout << endl;
    }

    return 0;
}
