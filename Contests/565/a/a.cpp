#include <bits/stdc++.h>

using namespace std;



int main (int argc, char *argv[]){
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long c = 0;
        while (n > 1) {
            c++;
            if(n%2 == 0){
                n >>= 1;
                continue;
            }        
            if (n%3 == 0) {
                n <<= 1;
                n /= 3;
                continue;
            }
            if(n%5 == 0){
                n <<= 2;
                n /= 5;
                continue;
            }
            c = -1;
            break;
        }
        cout << c << endl;

    }

    return 0;
}
