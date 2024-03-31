#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <vector>
#define psi string,int

using namespace std;

bool isWinner( string s, vector<string> winners){
    for (string i : winners) 
        if (i == s)
            return true;
    
    return false;
}


int main (int argc, char *argv[])
{
    int n,x;
    string s;
    map<psi> m;
    vector<pair<psi>> steps;
    vector<string> winners;
    
    cin >> n;
    for (int i = 0; i < n ; i++) {
        cin >> s >> x; 
        m[s] = m[s] + x;
        steps.push_back(make_pair(s,x));
    }

    int max = 0;
    for (pair<psi> i : m)
        if (i.second > max)
            max = i.second; 
    
    
    for (pair<psi> i : m){
        if (i.second == max) {
            winners.push_back(i.first);
        }
    }
    
    m.clear();
    for (pair<psi> i : steps) { 
        m[i.first] = m[i.first] + i.second;
        if (isWinner(i.first, winners) && m[i.first] >= max) {
            cout << i.first << endl;
            break;
        }
    }

    



    

    return 0;
}

