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
        vector<int> a(n), b(n);  

        for(auto &i: a) cin >> i;     
        for(auto &i: b) cin >> i;     
       
        ll sum = a[0]; 
        int mx = b[0];
        k--;

        ll asw = 0;
        for (int i = 1; i < n; i++) {
            if (k == 0) break; 
             asw = max(asw,sum + k*mx);
 
            sum += a[i];
            mx = max(mx,b[i]);
            k--; 
            
        }
             
        asw = max(asw,sum + k*mx);
        
        cout << asw << endl;



    }
    return 0;
}
