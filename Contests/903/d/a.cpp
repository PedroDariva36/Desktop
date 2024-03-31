#include <bits/stdc++.h>
#include <map>
#include <vector>
#define ll long long
using namespace std;

bool solve(map<int, int> &m, int n){
    for (auto &i : m) 
        if (i.second % n != 0)
            return false; 
    return  true;
}

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t,n;
    cin >> t; 
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        
        map<int,int> m; 
        for (auto k : a) {
            int i = 2;
            while(i * i <= k){
                while (k % i == 0){
                    m[i]++;
                    k /= i;
                }
                i++;
            }
            if(k > 1) m[k]++;
        }
        cout << (solve(m,n) ? "YES" : "NO") << endl; 
    }

    return 0;
}
