#include <bits/stdc++.h>
#include <cmath>
#define ll long long 
using namespace std;

int main (int argc, char *argv[]){
    long long n,k; 
    cin >> n >> k;
    long long m = n*2+1;
    long long res;
    long long asw = 0;
    
    for (long i = 2*n; i > 0; i--) {
        if (i*i == k) continue;

        res = abs((i * i) - k);
        if(res % m == 0) {
            asw = (i*i);
            break;
        }
    }

    cout << asw << endl;



    return 0;
}
