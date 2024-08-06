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
        ll a, b, c;
        cin >> a >> b >> c;
    
        ll k = abs(b-c);
        k += abs(c - 1);
        
        ll l = abs(a-1);

        if(l < k){
            cout << 1;
        } 
        else if (k < l){
            cout << 2;
        }
        else cout << 3;

        cout << endl;


         

    }
    return 0;
}
