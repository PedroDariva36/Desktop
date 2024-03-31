#include <bits/stdc++.h>
#include <numeric>

using namespace std;


int main (int argc, char *argv[]){
    
    int t;
    cin >> t; 
    while (t--) {
        long long a, b;
        cin >> a >>b;
        
        if(b%a != 0)
            cout << lcm(a, b) << endl;
        else
            cout << b*b/a << endl;



    }


    return 0;
}
