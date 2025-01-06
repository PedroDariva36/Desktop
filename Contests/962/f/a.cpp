#include <bits/stdc++.h>
#include <queue>
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
        int n, k;
        cin >> n;
    
        vector<ll> a(n); 
        vector<ll> b(n);

        for(auto &i: a)cin>> i;
        for(auto &i: b)cin>> i;


        priority_queue<pair<ll,ll>> q;
        for(int i = 0; i < n; i++){
            q.push({a[i], i});
        } 
        

        ll asw = 0;
        ll v, i; 
        while (k--) {
            tie(v,i) = q.top();
            q.pop();
            asw += v;
            q.push({max((v - b[i]), 0ll), i}); 
        }

        cout << asw << endl;
         

    }
    return 0;
}
