#include <bits/stdc++.h>
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
        if (n == 1) {
            cout << 1  << " "<< 1 << endl; 
            cout << 1 << " "  << 1 << " " << 1 << endl;
            continue;
        } 

        vector<int> p;
        for (int i = 1; i <= n; i++) {
             p.pb(i);
        }
        int k = n*(n+1);
        k >>= 1;



        vector<int> f;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            if (i*n < k) {
                f.push_back(i);
                sum += k;
            }
            else sum += i*(n-1) + n; 
        }

        int m[n+1][n+1];

        cout << sum << " " << n+n-1<< endl;
        if (f.size() > 0) {
            for(int i = f[f.size()-1]+1; i <=n; i++){
                cout << 2 << " ";
                cout << i << " ";
                for (auto j : p) {
                    cout << j << " "; 
                }
                cout << endl;
            } 
        }
        for(int i = 1; i <= n-1; i++){
            cout << 1 << " ";
            cout << i << " ";
            for (auto j : p) {
                cout << j << " "; 
            }
            cout << endl;
        } 
        for(auto i: f){
            cout << 2 << " ";
            cout << i << " ";
            for (auto j : p) {
                cout << j << " "; 
            }
            cout << endl;
        } 


    }

    return 0;
}
