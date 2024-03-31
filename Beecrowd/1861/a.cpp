#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <cstddef>
#include <ios>
#include <iostream>
#include <map>
#include <string>
using namespace std;



map<string, int> m;

int main (int argc, char *argv[]){
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1,s2;
    while (cin >> s1 >> s2) {
            m[s1]++;
            m[s2] = -1000000;
    }
 
    
    cout <<"HALL OF MURDERERS"<< endl;
    for (auto i : m) 
        if (i.second > 0)
            cout << i.first << " " << i.second << endl; 


    return 0;
}
