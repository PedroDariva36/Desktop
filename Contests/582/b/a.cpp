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
        for(auto &i: a) cin >> i;        
        

        ll mn = 1e9;
        ll c = 0;
    
        for (int i = n-1; i >= 0; i--) {
            if(a[i] > mn) {
                c++;
                continue;
            }
            mn = min(mn, a[i]);
        } 
        cout << c << endl;
        

    }
    return 0;
}
