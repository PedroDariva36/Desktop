#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

typedef pair<ll,ll> pll;


bool solve(vector<pll> &a, ll k){
   
    pll c = {0,0}; 
    for (int i = 0; i < a.size(); i++) {
       
        //cout << c.first << " " << c.second << endl;

        c.first -= k;
        c.second += k;
        
        //cout << c.first << " " << c.second << endl;



        if(c.first < a[i].first && c.second < a[i].first)
            return false;
        if(a[i].second < c.first && a[i].second < c.second)
           return false;


        c.first = max(a[i].first,c.first);
        c.second = min(a[i].second, c.second);
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
        
        vector<pll> a(n);
        for (auto &i: a) {
            cin >> i.first;
            cin >> i.second;
        }
        
        /*
        for (auto i: a) {
            cout << i.first << " " << i.second << endl;
        }
        
        //cout << solve(a, 7) << " - <<<<< " << endl;;
        */ 

        ll l = 0;
        ll r = 1e9;
        
        while(l < r){
            ll m = (l+r)>>1;
//            cout << m << endl;
            
            if(solve(a,m))
                r = m;
            else 
                l = m+1;
        }

        cout << l << endl;



        
         

    }
    return 0;
}
