#include <algorithm>
#include <bits/stdc++.h>
#include <valarray>

using namespace std;

int main (int argc, char *argv[]){
    
    int x1, x2, x3, y1, y2, y3;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    if (x1 == x2 && y1==y2 ) {
        cout << "YES" << endl;
        return 0;
    }

    int ax = abs(x1 - x2);
    int ay = abs(y1 - y2);

    if (ax % x3 > 0 || ay % y3 > 0) {
        cout << "NO" << endl;
        return 0;
    }
    
    if (((ax / x3) % 2) == ((ay / y3) % 2)) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    





    return 0;
}
