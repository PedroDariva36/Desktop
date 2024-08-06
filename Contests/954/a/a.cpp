#include <bits/stdc++.h>
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
        int a, b, c;
        cin >> a >> b >> c;
    
        int mn = 10;

        for (int i = 1; i <= 10;i++) {
            mn = min(mn, abs(a-i) + abs(b-i) + abs(c-i));
        } 

        cout << mn << endl;; 
                
         

    }
    return 0;
}
