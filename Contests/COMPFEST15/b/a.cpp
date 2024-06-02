#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

ll modpow(long x, long n, long m) {
    if (n == 0) return 1%m;
    ll u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) 
        u = (u*x)%m;
    return u;
}

const long MOD = 998244353;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n,m,x,y; 
        cin >> n;
        
        vector<int> a(n);
        vector<int> b(n);
       
        for(auto &i: a)
            cin >> i; 
        for(auto &i: b)
            cin >> i;



        cin >> m;
        vector<int> c(m);
        vector<int> d(m);

        for(auto &i: c)
            cin >> i; 
        for(auto &i: d)
            cin >> i;

        
        for (int i = 0; i < n; i++) {
            cout << modpow(a[i], b[i], MOD) << endl;  
        }
        cout << endl;

        for (int i = 0; i < m; i++) {
            cout << modpow(c[i], d[i], MOD) << endl;  
        }
        cout << endl;


    }
    return 0;
}
