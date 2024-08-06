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
        int n;
        cin >> n;
    
        if(n == 3){
            cout << -1 << endl;
            continue;
        }

        for (int i = n/2+1; i <= n; i++) {
            cout << i << " ";
        } 
        for ( int i = 1; i < n/2+1; i++) {
            cout << i << " ";
        } 
        cout << endl;

         

    }
    return 0;
}
