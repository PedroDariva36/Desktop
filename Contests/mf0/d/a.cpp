#include <bits/stdc++.h>

using namespace std;


int main (int argc, char *argv[]){
    long long x, rest, u; 
    cin >> x;
    
    long last = -1;
    while (x != last ){
        cout << x << endl;
        last = x;
        u = x % 10;
        rest = x/10;
        x = rest * 3 + u;

    }


    return 0;
}
