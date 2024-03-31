#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main (int argc, char *argv[]){
    int t, x;
    
    long y;
    cin >>  t;
    while (t--) {
        long sum = 0;
        cin >> x;
        for (int i = 0; i < x; i++) {
            cin >> y;
            sum += y;
        }
        
        

        int k = 1;
        while (true) {
            long y = k*k;
            if (y == sum) {
                cout << "YES" << endl;
                break;
            }
            
            if (y > sum) {
                cout << "NO" << endl;
                break; 
            }
            k++;
        }
        
    }

    return 0;
}
