#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define ull unsigned ll
using namespace std;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        map<ll, vector<ll>> m;

        ll n, k;
        cin >> n >> k;
        vector<ull> a(n);
        vector<ll> p(n);
        
        ll sum = 0;

        for(int i = 0; i < n ; i++){
            cin >> a[i];
            sum += a[i];
        }

        for(int i = 0; i < n ; i++){
            cin >> p[i];
            m[abs(p[i])].push_back(i);
        }
                
        if(n*k < sum){
            cout << "NO" << endl;
            continue;
        }


        bool f = false;
        ull r = 0;
        ull ex = 0;
        for (auto &i : m) {
            ull d = i.first - r;
            ull hsum = 0;
            ull bc = d*k + ex;
            ex = 0;

            for(auto &j: i.second) hsum += a[j];

            if(hsum > bc){
                f = 1;
                break;
            }
            ex = bc - hsum;
            r++;
        }

        if (!f) cout << "YES" << endl;
        else cout << "NO" << endl;





    }

    return 0;
}
