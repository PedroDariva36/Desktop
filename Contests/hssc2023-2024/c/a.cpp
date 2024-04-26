#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0); 
    int t;
    cin >> t; 
    while (t--) {
        long n;
        cin >> n;
        vector<long> d;
        

        int b = 63 - __builtin_clzl(n);
        long k = n - (1 << b);
        long l = 1; 
        for (int i = 0; i < 64; i++) {
            if((k&l) != 0){
                d.push_back(n);
                n-=l;
            }
            l <<= 1;
        } 


        while (n > 0) {
            d.push_back(n);
            n >>= 1; 
        }
        
        cout << d.size() << endl;
        for (auto &i : d) {
            cout << i << " "; 
        }
        cout << endl;




    }
}
