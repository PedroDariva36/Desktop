#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long
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
        
        vector<long> a(n);
        for (auto &i: a) {
            cin >> i;
        }
        

        vector<long> b;
        for (int i = 0; i < n-1; i++) {
            b.pb(max(a[i],a[i+1])); 
        }
        cout << *min_element(all(b))-1 << endl;
        
    }

    return 0;
}
