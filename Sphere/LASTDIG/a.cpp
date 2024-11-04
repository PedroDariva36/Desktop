#include <bits/stdc++.h>
#define ll  long long
#define endl '\n'
using namespace std;


const ll M = 10;
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        ll a, b ;
        cin >> a >> b; 
        cout << binpow(a,b,M) << endl;

    }

    return 0;
}
