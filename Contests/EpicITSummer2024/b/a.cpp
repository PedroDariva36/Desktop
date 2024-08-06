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
        vector<ll> a(n); 
        vector<ll> b; 

        for (auto &i : a) {
            cin >> i;
        }
        
        for (int i = 1; i < n; i++) {
            if(a[i] >= a[i-1]) continue;
            b.pb((a[i-1]-a[i])); 
            a[i] = a[i-1];
        }
        
        if(b.size() == 0){
            cout << 0 << endl;
            continue; 
        }
        sort(all(b));
        ll sum = 0; 
        ll mx = 0;
        /* 
        for (auto i: b) {
            cout << i << " ";
        }
        cout << endl; 
        */
        for (int i = 0; i < b.size(); i++) {
            ll aux = b[i];
            aux -= mx;
            sum += ((ll)b.size()-i+1)*aux;
            mx += aux;
        }
                


        cout << sum << endl;

         

    }
    return 0;
}
