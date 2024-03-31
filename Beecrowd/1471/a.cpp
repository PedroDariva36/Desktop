#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int n, r,x;
int main (int argc, char *argv[]){

    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> r) {
        unordered_map<int, bool> ret;
        for (int i = 0; i < r; i++) {
            cin >> x;
            ret[x] = true;
        }
        
        if (n == r) {
            cout << "*" << endl;
            continue;
        }

        for (int i = 1; i < n+1; i++)
            if (!ret[i])
                cout << i <<" ";
        cout << endl;

    }

    
    return 0;
}
