#include <algorithm>
#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
int main (int argc, char *argv[]){
    
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    
    string s;
    while (cin >> s) {
        long long counter = 0;
        bool flag = true;
        for (auto i : s){
            if (counter < 0) {
                flag = false;
                break;
            }

            if( i == '(') counter++;
            if( i == ')') counter--;
        }
        
        if (flag && counter == 0) {
            cout << "correct" << endl;
            continue;
        }

        cout << "incorrect" << endl;


    }

    return 0;
}
