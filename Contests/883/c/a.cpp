#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

bool comp(tuple<ll,ll,ll> a, tuple<ll,ll,ll> b) { 
    ll i,j,k;
    ll x,y,z;
    tie(i,j,k) = a;
    tie(x,y,z) = b;
    if(i != x) return i > x;
    else if(j != y) return j < y;
    else return k < z;  
}

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, m, h;
        cin >> n >> m >> h;

        vector<tuple<ll,ll,ll>> q;
        vector<vector<ll>> a(n,vector<ll>(m)); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            } 
        }

        for (ll i = 0; i < n; i++) {
            sort(all(a[i]));
            ll sum = 0;
            ll c = 0;
            ll penalt = 0;
            for(ll j = 0; j < m; j++) {
                if(sum + a[i][j] > h) continue;
                penalt += sum + a[i][j]; 
                sum += a[i][j];
                c++;
            } 
            q.pb({c,penalt,i});
        }
        
        sort(all(q), comp);
        
        ll x, y, p;
        ll c = 0;
        for (ll i = 0; i < n; i++) {
            tie(x,y,p) = q[i];
            //cout << x << " " << y << " " << p << endl;
            if(p == 0) c = 1+i;
        }
         
        cout << c  << endl;

         

    }
    return 0;
}
