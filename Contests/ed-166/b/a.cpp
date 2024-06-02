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



        bool f = false;
        ll k = b.back();
        ll sum = 0;
        ll d = k;
        for (int i = 0; i < n; i++) {
            sum += abs(a[i] - b[i]);
            ll x = a[i], y = b[i];
            if (x > y) swap(x,y);            
            if(k >= a[i] && k <= b[i]) f = true;
            if (f == false) d = min(min(abs(a[i] - k), abs(b[i] - k)),d); 
        }
        
        if(!f) sum+=d;

        sum++;
        cout << sum << endl;
    }

    return 0;
}
