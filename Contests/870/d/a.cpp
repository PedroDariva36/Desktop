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
        int n;
        cin >> n;
        vector<ll> a(n), pref(n), suf(n);
        for (auto &i : a) cin >> i;
        

        pref[0] = a[0];
        suf[n-1] = a[n-1]-(n-1);

        for (int i = 1; i < n; i++) 
            pref[i] = max(pref[i-1], a[i] + i);
        for (int i = n-2; i >= 0; i--) 
            suf[i] = max(suf[i+1], a[i] - i);

        ll mx = 0;
        for (int i = 1; i < n-1; i++) 
            mx = max(mx,pref[i-1] + a[i] + suf[i+1]);
        cout << mx << endl;
         

    }
    return 0;
}
