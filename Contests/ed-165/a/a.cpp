#include <bits/stdc++.h>
#include <iostream>
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
        vector<int> a(n);
        for (auto &i  : a) {
            cin >> i;
            i--;
        }
        int mx = n;
        for (int i = 0; i < n; i++) {
            int k = a[i];
            int size = 1;
            while (k != i) {
                k = a[k];
                size++;
            }
            if (size == 1) {
                continue;
            }
            if (size > 3) {
                size = 3;
            }
            mx = min(size, mx);
        }
        cout << mx << endl;

    }

    return 0;
}
