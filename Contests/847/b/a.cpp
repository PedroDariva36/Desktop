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
        int n,r,s;
        cin >> n >> s >> r;

        int mx = abs(r-s);
        
        vector<int> a;
        a.pb(mx); 
        for (int i = 1; i < n; i++) {
            a.pb(1);        
        }
    
        s -= mx;
        s -= (n-1);

        for (int i = 1; i < n; i++) {
            if(s == 0) break;
            if(s >= mx-1){
                a[i]+=mx-1;
                s-=mx-1;
            }
            else{
                a[i] += s;
                s = 0;
            }
        } 
         

        for (auto i: a) {
            cout << i << " ";
        }
        cout << endl;

         

    }
    return 0;
}
