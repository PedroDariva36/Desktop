#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        long n, k;
        cin >> n >> k;
            
        ll sum = 0; 
        while(n > 0){
            if (n >= k) {
                sum += (n - n%k);
                n %= k;
            }
            else {
                    
            }
        }


    }

    return 0;
}
