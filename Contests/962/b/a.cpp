#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n , m;
        cin >> n >> m;
    

        char a[n][n];
        vector<vector<char>> g;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        } 
        

        for (int i = 0; i < n; i+= m) {
            g.pb(vector<char>());
            for (int j = 0; j < n; j += m) {
                g.back().pb(a[i][j]);
            }
        } 

        
        for (auto i : g) {
            for(auto j : i) 
                cout << j;
            cout << endl;
        }

         

    }
    return 0;
}
