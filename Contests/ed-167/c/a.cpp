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
        vector<int> a(n), b(n);
        
        for(auto &i: a) cin >> i;
        for(auto &i: b) cin >> i;

        int x = 0, y = 0, k = 0, l = 0;
        
        for (int i = 0; i < n; i++) {
            if(a[i] > b[i]) x+= a[i]; 
            else if(a[i] < b[i]) y+= b[i]; 
            else { 
                l += (a[i] < 0);
                k += (a[i] > 0);
            } 
        } 
        int sum = -1e9;
        for (int i = -l; i <= k; i++) {
            sum = max(sum, min(x+i , y+(k-l-i)));
        }
         
        cout << sum << endl;




        
         

    }
    return 0;
}
