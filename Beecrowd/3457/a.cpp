#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    ll aux;     
    int n;
    cin >> n;

    unordered_map<ll, ll> m;
    vector<long> g(n), e(n);
    
    ll Se = 0;

    for (auto &i: g) cin >> i;
    for (auto &i: e){
        cin >> i;
        Se += i;
    }
    
    

    if (n == 1) {
        cout << g[0] + e[0] << endl;
        if ((g[0]-e[0]) > 0) 
            cout << g[0] - e[0] << endl;
    }
        
    sort(all(g));
    sort(rall(e));

    m[g[0] + e[0]]++;
    m[g[0] - e[0]]++;

    m[g[0] + e[1]]++;
    m[g[0] - e[1]]++;

    m[g[n-1] + e[0]]++;
    m[g[n-1] - e[0]]++;

    m[g[n-1] + e[1]]++;
    m[g[n-1] - e[1]]++; 

    
    for (auto &i: m) {
        if(i.first < 1  || i.first > 1e9 ) continue;
        ll s = 0;
        for (auto &j : g) s += abs(i.first - j);
        if(s == Se) cout << i.first << endl;
    }





    return 0;
}
