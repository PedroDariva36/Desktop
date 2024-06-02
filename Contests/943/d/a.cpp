#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

ll solve(vector<bool> &m, vector<int> &p, vector<long> &a, ll k, int x){
    if (m[x]) return 0;
    if (k == 0) return 0;
    
    m[x] = 1;
    ll aux = solve(m, p, a, k-1, p[x]) + a[x];
    
    ll v = (ll)k*a[x];

    if (aux > v) {
        return aux;
    }
    return v;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, p1, p2;
        cin >> n >> k >> p1 >> p2; 
        p1--;
        p2--;
        vector<long> a(n);
        vector<int> p(n);
        vector<bool> mp1(n,0);
        vector<bool> mp2(n,0);
        for (auto &i : p) {
            cin >> i;
            i--;
        }
        
        for (auto &i : a) {
            cin >> i; 
        }
        
        ll b = solve(mp1, p, a, k, p1);
        ll c = solve(mp2, p, a, k, p2);
        
        if (b > c) {
            cout << "Bodya" << endl;
        }
        else if(b == c){
            cout << "Draw" << endl;
        }
        else{
            cout << "Sasha" << endl;
        }

    }

    return 0;
}
