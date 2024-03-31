#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main (int argc, char *argv[]){
    int t; 
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        int cnt = 0;
        string og = s;
        do {
            string s2 = s;
            reverse(s2.begin(), s2.end());
            if (s2 == s && s2 != og) {
                cnt += 1;
            }

        } while (next_permutation(s.begin(), s.end()));
        

        if (cnt > 0) {
            cout << "YES" <<endl;
        }
        else {
            cout << "NO" << endl;
        }
    }


    return 0;
}
