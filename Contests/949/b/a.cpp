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
        int n,m;
        cin >> n >> m;
        
        vector<int> b(n+1), a(n+1);
        int c = 0;
        for (auto &i : a) i = c++;
        
        b[0] = a[0]|a[1]; 
        for (int i = 1; i < n; i++) {
            b[i] = a[i-1] | a[i] | a[i+1];
        }
        b[n] = a[n-1]|a[n]|n+1;

        for (auto i :b) {
            cout << i << " ";
        }
        cout << endl;
        m--;
        
        a = b;
        while (m--) {
            b[0] = a[0]|a[1]; 
            for (int i = 1; i < n; i++) {
                b[i] = a[i-1] | a[i] | a[i+1];
            }
            b[n] = a[n-1]|a[n]|n+1;

            for (auto i :b) {
                cout << i << " ";
            }
            cout << endl;
            a = b;
        }


    }

    return 0;
}
