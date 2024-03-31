#include <bits/stdc++.h>

using namespace std;


int main (int argc, char *argv[]){
    
    int x, y, z;
    cin >> x >> y;

    if (x == y) {
        z = x;
    }
    if (x != y) {
        z = max(x,y);
    }
    cout << z;

    return 0;
}
