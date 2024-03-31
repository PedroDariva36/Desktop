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
        ll sum = 0;
        ll aux = 0;

        for (int i = 0 ; i < n; i++) {
            cin >> aux;
            sum += abs(aux);
        }        
        cout << sum << endl;
    }

    return 0;
}
