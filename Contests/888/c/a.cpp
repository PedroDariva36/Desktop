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
        cin >> n >> k;
    
        vector<ll> a(n); 
        for(auto &i: a) cin >> i; 
        
        ll c = 0;
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if(a[i] == a[0]) c++;
            pos = i;
            if(c == k) break;
        }
        
        if(c != k){
            cout << "NO" << endl;
            continue;
        }
        
        if(a[0] == a[n-1] && c == k || pos == n-1){
            cout << "YES" <<endl; 
            continue;
        }

        c = 0; 
        for (int i = pos+1; i < n; i++) {
            if(a[i] == a[n-1]) c++;
            pos = a[i];
            if(c == k) break;
        }

        cout << (c == k?"YES":"NO") << endl;


         

    }
    return 0;
}
