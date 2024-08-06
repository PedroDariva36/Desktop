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
        ll n, m;
        cin >> n >> m;
        set<ll> s; 
        
        ll k = m;
        while (k <= n) {
            ll d = k%10; 
            if(s.count(d) == 1) { 
                k -= m;
                break;
            }
            s.insert(d);
            k += m; 
        } 
        
        ll dsum = 0;
        for (auto i: s) dsum += i;
        
        if(s.size() == 0){
            cout << 0 << endl;
            continue;
        }

        
        ll asw = dsum * ((n/m)/(ll)s.size());
        ll l = (n/m)%s.size(); 
        if(l){
            s.clear();
            k = m;
            while (s.size() < l) {
                s.insert(k%10);
                asw += k%10;
                k+=m;
            }
        }
        cout << asw << endl;




    }
    return 0;
}
