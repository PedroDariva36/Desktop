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
        ll n, mx = 0, w;
        cin >> n >> w;
        map<ll,ll>m; 
        ll aux; 
        for (int i = 0; i < n; i++) {
            cin >> aux;
            m[aux]++;
        }
        for (auto i: m) {
            if(m.count(i.first+1) == 0) {
                ll fc = i.second; 
                ll c = 0;
                while (fc > 0) {
                    if((c * i.first) + i.first > w) break;
                    fc--;
                    c++;
                    mx = max(mx,c*i.first);
                }
                continue;
            }
            ll fc = i.second;
            ll sc = m[i.first+1];
             

            pair<ll, ll> p = {0,0};

            while (fc > 0) {
                if((p.first * i.first) + (p.second * (i.first+1)) + i.first > w) break;
                fc--;
                p.first++;
                mx = max(mx,p.first*i.first + p.second * (i.first+1));
            }

            while (sc > 0) {
                if((p.first * i.first + p.second * (i.first+1)) + i.first+1 > w) {
                    if(p.first == 0) break;
                    p.first--;
                    continue;
                }
                sc--;
                p.second++;
                mx = max(mx,p.first*i.first + p.second * (i.first+1));
            }
 
        }

        cout << mx << endl;

    }        

    return 0;
}
