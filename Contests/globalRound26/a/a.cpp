#include <bits/stdc++.h>
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
        int n;
        cin >> n;
        
        vector<long> a(n);
        vector<bool> marked(n);
        for (auto &i :a ) {
            cin >> i;
        }    

        
        long m = abs(a[0] - a.back());
        
        if(m == 0){
            cout << "NO" << endl;
            continue;
        }
    
        marked[1] = true;
        cout << "YES" << endl;
        for (auto i :marked) {
            if(i) cout << "B";
            else cout << "R";
        } 
        cout << endl;

    }

    return 0;
}
