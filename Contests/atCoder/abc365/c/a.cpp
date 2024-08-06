#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


ll solve(vector<ll> &a, ll x){
    ll sum = 0;
    for (auto i : a) {
        sum += min(x,i);
    }   
    return sum;
}

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n); 
    
    for(auto &i: a) cin >> i;

    
    ll l = 1, r = m;

    while (l < r) {
        ll mid = l + (r - l + 1) / 2; 
        if(solve(a,mid) <= m){
            l = mid;
        }
        else r = mid-1;
    } 

    if(l == m){
        cout << "infinite" << endl;
        return 0; 
    } 
    
    cout << l << endl;






    return 0;
}
