#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    long aux;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        

        set<ll> s;
        vector<ll>a;
        for (int i = 0; i < n; i++){
            cin >> aux; 
            s.insert(aux);
        }

        if (n == 1) {
            cout << 1 << endl;
            continue; 
        }


        for (auto &i : s) a.push_back(i);

        ll sum = 0;
        ll g = 0;
        ll mx = a[n-1];
        ll k = 1;

        for (int i = 0; i < n-1; i++) 
            g = gcd(g,abs(a[i] - a[i+1]));
        
        while (s.count(mx-g*k) > 0) 
            k++;
        
        a.push_back(mx-g*k);    
        for (auto i : a) 
            sum += (mx - i)/g;

        cout << sum << endl;
    }

    return 0;
}
