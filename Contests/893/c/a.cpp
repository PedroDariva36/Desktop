#include <bits/stdc++.h>
#include <vector>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int,vector<int>> m;
        m[2].push_back(1);
        for(int i = 2; i <= n; i++) {
            int k = i;
            while (k % 2 == 0) {
                k >>= 1;
            }
            m[k+1].push_back(i);
        }
        
        for (auto &i : m) {
            for (auto &j : i.second) {
                cout << j << " "; 
            } 
        }
        cout << endl;
    }

    return 0;
}
