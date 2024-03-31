#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]){
    

    int n, m, aux;
    cin >> n >> m;
    
    

    int array[n];
    while (m--) {
        for (int i = 0; i < n; i++) {
            cin >> aux;
            array[i] += aux;
        }
    }

    int mx = -1;
    for (int j = 0; j < n; j++) {
            mx = max(array[j],mx);
    }
    
    for (int i = 0; i < n; i++ ) {
        if (array[i] == mx) {
            cout << i+1 << endl;
            break;
        }
    }
    return 0;
}
