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
    //cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> a(n),b(n,0);   
        
        for (auto &i : a) cin >> i;

        b[n-1] = a[n-1];
        for(int i = n-2; i >= 0; i--){
            if(a[i] <= a[i+1]){
                b[i] = (b[i+1] - (a[i]-1)) + a[i];
            }
            if(a[i] > a[i+1]){
                if(abs(a[i] - a[i+1]) <= (b[i+1] - (a[i+1])))
                    b[i] = b[i+1] + 1;
                else{
                    b[i] = a[i];

                }
            }
        }
        /*    
        for (auto i: b) {
            cout << i << " ";
        }
        cout << endl;
        */
        
        cout << *max_element(all(b)) << endl;
    }
    return 0;
}
