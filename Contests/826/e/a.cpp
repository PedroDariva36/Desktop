#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


bool solve(ll i, ll k , vector<ll> &a){
    
    if(i == (int)a.size() && k == 0) return 1; 
    if(i >= a.size()) return 0;
    if(i == (int)a.size()-1 && k == a[i]) return 1;
       

    bool f =0, g = 0 ,h = 0;
    if(a[i] == k) 
        f = solve(i+1, 0, a);    
    if(k == 0)
        g = solve(i+(a[i]-1),0,a);
    h = solve(i+1,k+1, a);  


    return f|g|h; 
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> a(n); 
        for(auto &i: a) cin >> i;
    
        cout << solve(0,0,a) << endl;; 




    }
    return 0;
}
