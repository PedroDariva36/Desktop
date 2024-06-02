#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
        ll sum = 0;
        vector<long> a(n);
        for (auto &i : a) {
            cin >> i;
            sum += i;
        }

        ll k = 0;
        ll s = 0;
        for (int i = 0; i < n-1; i++) {
            k += a[i];
            sum -= a[i];
            s = max(s, gcd(k, sum));
        } 

        cout << s << endl;

    }
}
