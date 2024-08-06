#include <bits/stdc++.h>
#include <sstream>
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
    int n, m;
    ll k;
    cin >> n;
    cin.ignore();
    vector<vector<string>> g(n);
    vector<ll> val(n); 


    string aux, aux2;
    for (int i = 0; i < n; i++) {
        getline(cin, aux);
        stringstream ss(aux);
        while(ss >> aux2)    
            g[i].pb(aux2);
    }
    

    cin >> m;
    map<string, ll> a;
    while(m--){
        cin >> aux >> k;
        a[aux] = k;
    } 
    
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        for (auto j: g[i]) {
            sum += a[j];
            val[i] += a[j];
        } 
    } 
    

    int pos = 0;
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        if(val[i] >= mx){
            pos = i;
            mx = val[i];
        }
    }
    
    cout << sum << " " << pos+1 << endl;


    

    

    return 0;
}
