#include<bits/stdc++.h>
#include <vector>
using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i; 
        }

        int c = 0;
        for (auto &i: a) 
            c += i - (c%i); 
        
        cout << c << endl;

    }


    
    return 0;
}
