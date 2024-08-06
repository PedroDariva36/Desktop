#include <bits/stdc++.h>
#include <queue>
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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> d(n);
        vector<int> m(n,0);
        vector<vector<int>> g(n); 
        
        for (auto &i: d) {
            cin >> i;
        }
        
        for (int i = 0; i < n-1; i++) {
            int x, y;
            cin >> x >> y;
            g[x-1].pb(y-1);
            g[y-1].pb(x-1); 
        } 
        ll s0 = 0;

        priority_queue<pair<ll,int>> q;
        for (int i = 0; i < n; i++) {
            q.push({d[i],i});        
        }
        
        while (!q.empty()) {
            ll v, i; 
            v = q.top().first;
            i = q.top().second;
            q.pop();

            if(m[i] == 1) continue;
            m[i] = 1;
        

            s0 += d[i]; 
            for (auto u: g[i])
                m[u] = 1; 
        }



        ll sum = 0;
        for (auto i:d) {
            sum += i;
        } 
        ll h = sum;
        ll a = (sum - s0);
        ll b = s0;
        h += min(a,b);


        cout << h << endl;


        






    }
    return 0;
}
