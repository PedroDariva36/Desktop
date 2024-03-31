#include <algorithm>
#include <bits/stdc++.h>
#include <cfloat>
#include <cmath>
#define ll long long
using namespace std;

int main (int argc, char *argv[]){
    long double a,b,c;
    char x;
    
    cin >> a >> b >> c >> x;
    
    if (x == 'A'){
        a += (b*3)/2 + c*2.5;
        cout << (ll)a << endl;
    }
    else if (x == 'B'){ 
        b += (a*2)/3 + (c*5)/3;
        cout << (ll)b << endl;
    }
    else{ 
        c += a/2.5 + (b*3)/5;
        cout << (ll)c << endl;
    }


    return 0;
}
