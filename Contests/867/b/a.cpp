#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;



int t, n;
ll maxf, maxs, aux;
int main (int argc, char *argv[]){
    
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> a;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            a.push_back(aux);
        }
        sort(a.begin(), a.end());

            

        cout << max(a[a.size()-1] * a[a.size()-2],a[0]*a[1]) << endl;
    }

    return 0;
}
