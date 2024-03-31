#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long aux;
        map<long, long> m;
        for (int i = 0; i<n; i++) {
            cin >> aux;
            m[aux]++;
        }
        if (m.size() == 1 || m[1] > 1) {
            cout << "NO" << endl;   
            continue;
        }
        
        int g = 0;
        for (auto &i : m){
            if (i.second == 0) continue;
            g = gcd(g, i.first);
        }
        
        if (m[g] > 1) {
            cout << "NO" << endl;
            continue; 
        }  

        cout << "YES" << endl;
        


    }

    return 0;
}
