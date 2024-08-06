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
        
        for (auto &i : a) {
            cin >> i;
        }
        ll mx = 0;
        for (int i = 0; i < n-1; i++) {
            mx = max(mx,a[i]);  
        } 
        cout << mx + a.back() << endl; 





        
         

    }
    return 0;
}
