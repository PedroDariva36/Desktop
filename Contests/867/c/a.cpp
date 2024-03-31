#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t;
ll x, a, b;
int main (int argc, char *argv[]){
    cin >> t;    
    while (t--){
        cin >> x;
        a = x-1;
        b = x-2;
        cout << (4*x) + 1 + (a*a + a)/2 + (b*b + b)/2<< endl;
    }

    return 0;
}
