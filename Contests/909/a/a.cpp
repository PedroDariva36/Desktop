#include "bits/stdc++.h"

using namespace std;


int main (int argc, char *argv[]){
    int t, n ;
    cin >> t;
    while (t--) {
        cin >> n;
        
        if ((n+1) % 3 == 0 || (n-1) % 3 == 0) {
            cout << "First" << endl;
        }
        else {
            cout << "Second" << endl;
        }
    }


    return 0;
}
