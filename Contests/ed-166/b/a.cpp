#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <utility>
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
        vector<ll> a(n), b(n+1); 

        for (auto &i : a) cin >> i; 
        for (auto &i : b) cin >> i; 


        ll sum = 0;
        ll mn = 1e12;
        for (int i = 0; i < n; i++) {
            sum += abs(a[i] - b[i]);
            mn = min(mn, min (abs(a[i] - b[n]), abs(b[i] - b[n])));
            if (min(a[i], b[i]) <= b[n] && b[n] <= max(a[i], b[i]))
                mn = 0;
        }
        cout << sum + mn + 1 << endl;; 

    }

    return 0;
}
