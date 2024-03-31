#include <bits/stdc++.h>
#define ll long long


const long k = 100'100'100;

using namespace std;

int main (int argc, char *argv[]){
    cout << k << endl;
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i * i <= n; i++) {
            if (n%i == 0) { 
                cout << i << " ";
                if (n/i != i)  cout << n/i << " "; 
            } 
        } 
        cout << endl;        
        //4 1 2 4


       // n -> sqrt(n)
        

        //n = q*p;
        //n/q = p

        //100 = 1 * 100
        
        //100 = 2 * 50
        //
        //100 = 4 * 25
        //
        //100 = 5 * 20
        //
        //100 = 10 * 10
    

    }

    return 0;
}
