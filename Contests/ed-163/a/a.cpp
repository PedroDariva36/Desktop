#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        if(n % 2 == 1){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl; 
        for (int i = 0; i < n/2; i++) {
            cout << (i%2==0? "BB" : "AA");
        }
        cout << endl;
    }

    return 0;
}
