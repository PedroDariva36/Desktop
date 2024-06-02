#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b ;
        
        ll k = 1;
        int c = 0;
        while ((k << 1) <= b) {
            k <<= 1;
            c++;
        }
        cout << c << endl;



    }

    return 0;
}
