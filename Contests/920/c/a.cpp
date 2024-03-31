#include <bits/stdc++.h>
#include <ios>
#include <vector>
#define ll long long
using namespace std;

int main (int argc, char *argv[]){
    int l;
    cin >> l;
    while (l--) {
        int n;
        ll c, t, k, aux;
        cin >> n >> c >> t >> k;
        vector<ll> a;

        a.push_back(0);
        for (int i = 0; i < n; i++) {
            cin >> aux;
            a.push_back(aux);
        }
        
        bool asw = 1;
        for (int i = 0; i < n; i++) {
            ll e = abs(a[i]-a[i+1]) * t;
            if (e > k) c -= k;
            else c -= e;
             

            if(c <= 0){
                asw = 0;
                break;
            }
        }

        if (asw) cout << "YES";
        else cout << "NO";
        cout << endl;


    }


    return 0;
}
