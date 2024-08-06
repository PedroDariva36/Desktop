#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


ll solve(ll h, ll c2, ll c3, vector<ll> &a, ll pos){
    if(pos >= a.size()) return 0;
         
    if(h > a[pos]){
        return (1 + solve(h + (a[pos]>>1), c2, c3, a, pos+1));
    }
    return max(
        (c2? solve(h*2, c2-1, c3, a, pos): 0),
        (c3? solve(h*3, c2, c3-1, a, pos): 0)
    );
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, h;
        cin >> n >> h;
        vector<ll> a(n);

        for (auto &i : a) {
            cin >> i;
        }
    
        sort(all(a));


        cout << solve(h,2,1,a,0) << endl;


        

        
         

    }
    return 0;
}
