#include <bits/stdc++.h>
#include <set>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        long aux;
        cin >> n;
        
        vector<long> a(n), b(n);
        for (auto &i :a) cin >> i;
        for (auto &i :b) cin >> i;

        cin >> d;
        multiset<long> m;
        
        long u = -1;
        for (int i = 0; i < d; i++) {
            cin >> aux;
            m.insert(aux);
            if (i == d-1) {
                u = aux;
            } 

        }
        bool f = true; 
        for (int i = 0; i < n ; i++) {
            if (a[i] == b[i]) continue;
            auto it = m.find(b[i]);
            if (it != m.end()) {
                m.erase(it);
                continue;
            }
            
            f= false;
            break;

        }
        
        if(f && m.size() != 0){
            f = false;
            for (int i = 0; i < n; i++){
                if (b[i] == u) {
                    f = true;
                }
            }
        }


        cout << (f? "YES": "NO") << endl;

        

        

    }

    return 0;
}
