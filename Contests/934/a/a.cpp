#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        if (k < n-1)
            cout << n << endl;
        else {
            cout << 1 << endl;     
        }
    }

    return 0;
}
