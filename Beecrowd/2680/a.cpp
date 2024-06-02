#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll sum= 0;
        long n; 
        cin >> n; 

        for (int i = 1; i*i <= n; i++) {
            if (n%i == 0) {
                sum += i;
                if (n/i != i) sum += n/i;   
            } 
        }
        cout << sum << endl;
    } 



    return 0;
}


