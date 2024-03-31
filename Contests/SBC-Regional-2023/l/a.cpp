#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main (int argc, char *argv[]){
    int k; 
    string s;
    cin >> s >> k;
    
    vector<char> g[k];

    for (int i = 0 ; i < s.size(); i++) {
        g[i%k].push_back(s[i]);
    }
    
    for (auto &i : g) sort(i.begin(),i.end());
    
    int j = 0;
    int x = s.size()/k + 1 * (s.size()%k);
    //cout << x << endl;
    for(int j = 0; j < x; j++)    
        for (int i = 0; i < k ; i++){
            if(j >= g[i].size()) break; 
            cout << g[i][j];
        }
    cout << endl;
    
    return 0;
}
