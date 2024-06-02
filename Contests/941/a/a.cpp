#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    int t;
    cin >> t;
    while (t--) {
        int n,aux,k;
        cin >> n >> k;
        
        int mx = 0;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            m[aux]++;
            mx = max(mx,m[aux]);
        }
    
        if (mx < k) {
            int sum = 0;
            for (auto i: m) {
                sum += i.second; 
            }
            cout << sum << endl;
            continue;
        }
        vector<int> v; 
        for (auto i: m) {
            v.push_back(i.second); 
        }
        sort(v.rbegin(),v.rend());
        
        int ct = 0;
        for (auto i: v) {
            if (i >= k) {
                ct += i-1; 
            }
            else{
               ct -= (k-i);
               ct += k-1;
            }
        } 
        
        if (ct  >= k) {
            cout << k-1 << endl;
        }
        else {
            cout << ct << endl;
        }



         
    }        

    return 0;
}
