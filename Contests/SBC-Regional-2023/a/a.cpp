#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]){
    
    int n,m, aux, sum = 0;

    cin >> n;
    cin >> m;
    while (n--) {
        cin >> aux;
        if (m >= aux) sum++;
    }
    cout << sum << endl;

    return 0;
}
