#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]){
    int n;
    string s;
    cin >> n >> s;
    
    reverse(s.begin(), s.end());
    s[s.size()-2] = s[s.size()-2] -32;
    s[1] = s[1] - 32;
    
    cout << s << endl;
    return 0;
}
