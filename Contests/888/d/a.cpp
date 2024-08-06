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
    //cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n = 1;
        cin >> n;
        vector<ll> a;
        map<ll , int> m;
    

        ll aux = 0;
        for(int i = 0; i < n-1; i++) {
            cin >> aux;
            a.pb(aux);
        }


        m[a[0]]++;
        bool f = 0;
        for (int i = 1; i < n-1; i++)  m[a[i] - a[i-1]]++;
        

        vector<ll> b,c; 
        for (int i = 1; i <= n; i++) {
            if(m.count(i) > 0) continue;
            b.pb(i);
        }
        
        for (auto i: m) {
            if(i.second >= 3){
                f = 1;
                break;
            } 
            if(i.first > n){
                c.pb(i.first);
                continue;
            } 
            if(i.second == 1) continue;
            c.pb(i.first);
        }


        if (f || c.size() >= 2 || b.size() >= 3) {
            cout << "NO" << endl;
            continue;
        }
        
        if(b.size() == 1 && c.size() == 0){
            cout << "YES" << endl;
            continue;
        }

        if(b.size() == 2 && c.size() == 1)
            cout << (b[0] + b[1] == c[0] ?"YES":"NO") << endl;
        else
            cout << "NO"<< endl;;
    }
    return 0;
}
