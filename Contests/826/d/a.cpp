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
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        ll sum = 0;
        bool f = 0; 
        ll m = 1;
        while (m < n) {

            vector<ll> b;
            /*
            for (auto i: a) {
                    cout << i << " ";
                }
            cout << endl;
            */
            for (ll i = 0; i < (ll)a.size()-1; i += 2) {


                if(abs(a[i]-a[i+1]) == m){
                    if(a[i] > a[i+1]){
                        sum++;
                        b.pb(a[i+1]);
                    }
                    else b.pb(a[i]);
                }
                else f = 1;
            } 
            if(f == 1) break;
            a = b;
            m *= 2;
        }

        cout << (f? -1: sum) << endl;
         

    }
    return 0;
}
