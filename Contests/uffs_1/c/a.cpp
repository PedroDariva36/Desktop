#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll n){
    ll sum = 0; 
    ll a = n;

    while (a) {
        sum += a % 10;
        a = a/10;
    }
    
    return n - sum;
}


int main (int argc, char *argv[]){
    
    ll n, s, counter = 0;

    cin >> n >> s;
    
    int k = s;
    while (k) {
        if (solve(k) >= s) break;
        if (k > n) {
            cout << 0 << endl;
            return 0;
        }
        k++;
    }
        
    cout << n - k + 1 << endl;



    return 0;
}
