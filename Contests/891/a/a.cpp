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
        vector<ll> a;
        vector<ll> b;
        ll aux;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            if(aux%2 == 0){
                a.pb(aux);
            }
            else {
                b.pb(aux);
            }
        } 

        if (b.size() % 2 == 1 ) {
            cout << "NO" << endl;
            continue;
        }
        
        cout << "YES" << endl;;

    }
    return 0;
}
