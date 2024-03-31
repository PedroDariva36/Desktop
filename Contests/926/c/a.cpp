#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int k, x, a;
        cin >> k >> x >> a;

        if (k == x) {
            cout << "NO" << endl;
            continue;
        }

        if (k == x-1){
            if (a >= x+2) {
                cout << "yes" << endl;
            }
            else {    
                cout << "NO" << endl;
            }
            continue;
        }
        if(k > x){ 
            if (a >= x+2) {
                cout << "yes" << endl;
            }
            else {    
                cout << "NO" << endl;
            }
            continue;
        }
        cout << "No" << endl;


    }
    return 0;
}
