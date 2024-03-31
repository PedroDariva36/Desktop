#include <bits/stdc++.h>
#include <numeric>
#define ll long long
using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        long long a = 1; 
        for (long long i = 2; i*i <= n; i++) {
            if (n%i == 0) {
                ll la =lcm(a, abs(n-a));
                if (la > lcm(i, abs(n-i))) 
                    a = i; 

                if (n/i != i){
                    ll k = n/i; 
                    if (la > lcm(k, abs(n-k))) a = n/i;
                }
            }
        }
        
        cout << a << " " << n-a << endl;
    }


    return 0;
}
