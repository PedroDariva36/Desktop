#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


bool solve(int mid, vector<pair<int,int>>&a, vector<int> &b, int n){
    vector<bool> c(n,0);
    vector<int> pref;
    for (int i =0; i <= mid; i++)
        if(c[b[i]] == 0) c[b[i]] = 1;
    ll sum = 0; 
    for (int i = 0; i < n; i++) {
        sum += c[i];
        pref.pb(sum);    
    } 

    for (auto i: a) {
        if(pref[i.second] - pref[i.first] + c[i.first] > (i.second - i.first+1)/2)
            return true;
    } 




    return false;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, q;
        cin >> n >> m;
        vector<pair<int,int>> a(m);
        
        for (auto &i : a){
            cin >> i.first >> i.second;
            i.first--;i.second--; 
        }
        cin >> q;
        vector<int> b(q);
        for (auto &i: b) {
            cin >> i;
            i--;
        }
        
        if(solve(q-1,a, b, n) == 0){
            cout << -1 << endl;
            continue;
        } 
        /* 
        for(int i = 0; i < q; i++){
            cout << solve(i,a,b,n) << endl;
        }
        */

        
        int l = 0; int r = q-1; 
        while (l < r) {
            int mid = (l+r)/2;
            if(solve(mid, a, b ,n)){
                r = mid;
            }
            else l = mid + 1;
        } 
        
        //cout << solve(2, a, b, n) << endl;

        cout << l+1 << endl;;





        






         

    }
    return 0;
}
