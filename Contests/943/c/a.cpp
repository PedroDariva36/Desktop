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
        vector<ll> a(n-1);
        vector<ll> b;
        for (int i = 0; i < n-1; i++) {
            cin >> a[i]; 
        }
        long last = 2*1e5;
        b.push_back(last); 
        for (int i = 0; i < a.size(); i++) {
            b.push_back(last + a[i]);
            last += a[i];
        }
        
        for (auto i : b) {
            cout << i << " "; 
        }
        cout << endl;

    }

    return 0;
}
