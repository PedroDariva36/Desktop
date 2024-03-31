#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>

using namespace std;

int main (int argc, char *argv[]){
    int a,b,c,x,y,z; 
    cin >> a >> b >> c >> x >> y >> z;
    double n = (x-a)*(x-a) + (y-b)*(y-b) + (c-z)*(c-z);
    n = sqrt(n);
    cout << setprecision(12) << n << endl;

    return 0;
}
