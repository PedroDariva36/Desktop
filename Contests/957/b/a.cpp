#include <algorithm>
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
        int n, k;
        cin >> k >> n;
        
        vector<ll> a(n);
        for (auto &i: a) {
            cin >> i; 
        } 

        sort(rall(a));
        ll sum = 0;
        for (int i = 1; i < n; i++) {
            sum += a[i]-1 + a[i];
        }

        cout  << sum << endl; 




         

    }
    return 0;
}
