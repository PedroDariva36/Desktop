#include <bits/stdc++.h>
#include <iterator>
#include <vector>
#define ll long long
const ll M = 1e10;

using namespace std;

int main (int argc, char *argv[]){
    int t;
    cin >> t;

    while (t--) {
        int n;
        ll x, a;
        vector<ll> v;
        ll lower = M , upper = -M;
        
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a >> x;  
            if(a == 1 && x > upper) upper = x; 
            if(a == 2 && x < lower) lower = x;
            if (a == 3) v.push_back(x);
        }
        if (upper > lower) cout << 0 << endl;
        else {
            ll asw = lower - upper + 1;
            int dist = 0;
            for (auto i : v) if (i <= lower && i >= upper) dist++;
            cout << asw - dist << endl;;
        }
    }

    return 0;
}
