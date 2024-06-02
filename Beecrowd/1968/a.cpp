#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;
const long mod = 1e9 + 7;
const long N = 1e7+1;
int sv[N];

void siv(int n){
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            ++sv[j];   
}


ll modpow(ll x, ll n, ll m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) 
        u = (u*x)%m;
    return u;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    ll ld = 0;
    long m, n, k;
    cin >> m >> n >> k;
    
    siv(n);
    for (int i = m; i <= n; i++)
        if (sv[i] == k) 
            ld++; 

    cout << modpow(ld, (abs(n-m+1)-ld), mod) << endl;


    return 0;
}
