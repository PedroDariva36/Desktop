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
        ll n, mx = 0, w;
        cin >> n >> w;
        map<ll,ll>m; 
       
        vector<ll> a(n), b(n);
        for (auto &i : a) cin >> i;        
        for (auto &i : b) cin >> i;        
        
        for (int i = 0; i < n; i++) {
            m[a[i]] = b[i];
        }

        for (auto i: m) {
            if(m.count(i.first+1) == 0) {
                ll fc = i.second; 
                ll c = 0;
                c = min(w/i.first,fc);     
                mx = max(mx,(c*i.first));  
                continue;
            }

            ll fc = i.second;
            ll sc = m[i.first+1];

            ll c1,c2,dif;
            
            c1 = min(w/i.first, fc);
            c2 = min((w - c1 * i.first)/(i.first+1), sc);
            dif = w - c1 * i.first - c2 * (i.first+1);
            mx = max(mx, c1 * i.first + c2 * (i.first+1) + min(min(c1,sc - c2),dif));   

        }

        cout << mx << endl;

    }        

    return 0;
}
