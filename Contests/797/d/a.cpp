#include <bits/stdc++.h>
#include <cstdlib>
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
        cin >> n >> k;
        
        vector<char> a(n);
        vector<ll> pref; 

        ll sum = 0; 
        for(auto &i: a){
            cin >> i;
            sum += (i == 'W'? 1:0);
            pref.pb(sum); 
        }

        ll mn = pref.back();

        for (int i = 0; i < n-(k-1); i++) {
            mn = min(pref[i+k-1] - pref[i] + (a[i] == 'W'? 1:0), mn);
        } 

        cout << mn << endl;
        
    }
    return 0;
}
