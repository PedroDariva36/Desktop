#include <bits/stdc++.h>
#include <map>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(x) push_back(x)
using namespace std;

bool solve(ll k, map<ll, int> &m){
    ll sum = 0; 
    for (auto &i: m) {
        if(i.first <= k) {
            sum += i.first*i.second;
            continue; 
        }
        
        if(sum < i.first) return false;
        sum += i.first*i.second;
    } 

    return true;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> a(n), b, c;    
        map<ll,int> m;

        for (auto &i : a) {
            cin >> i;
            m[i]++; 
        }
        
        for (auto &i : m) b.pb(i.first);
        

        int l = 0;
        int r = b.size();
        while (l < r) {
            int mid = (l+r)>>1;
            (solve(b[mid], m)? r = mid: l = mid+1);
        }
        
        for (int i = 0; i < n; i++) if(a[i] >= b[l]) c.pb(i+1);
        
        cout << c.size() << endl;
        for (auto i: c) cout << i << " ";
        cout << endl;
    

    }
    return 0;
}
