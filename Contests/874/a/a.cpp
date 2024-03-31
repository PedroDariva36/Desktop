#include <bits/stdc++.h>
#include <map>
#include <vector>

using namespace std;

int main (int argc, char *argv[]){
    
    int t, n;
    char c;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<char> s;
        map<string, int> m;
        for (int i = 0; i < n; i++) {
            cin >> c;
            s.push_back(c);
        }
        
        for (int i = 0; i < s.size()-1; i++) {
            string x;
            x.push_back(s[i]); 
            x.push_back(s[i+1]);
            m[x]++;
        }

        cout << m.size()<<endl;
        
    }


    return 0;
}
