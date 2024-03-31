#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long


int main (int argc, char *argv[]){
    string s;
    cin >> s;
    vector<string> k;
    sort(s.begin(), s.end());

    do k.push_back(s);
    while(next_permutation(s.begin(),s.end()));
    
    cout << k.size() << endl;
    for(auto &i: k){
        cout << i << endl; 
    }

    return 0;
}
