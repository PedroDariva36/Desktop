#include <bits/stdc++.h>
#include <ios>
#include <unordered_map>
#include <vector>
#define ll long long


using namespace std;
int n;
ll x;
int main (int argc, char *argv[]){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    while (cin >> n) {
        if (n == 0) break;
        unordered_map<ll, ll> m;
        vector<ll> a;
        for (int i = 0; i < n; i++) {
            cin >> x;
            m[x]++;
        }

        for (auto i : m) {
            if (a.size() > 1) break;
            if (i.second % 2 != 0) a.push_back(i.first);
        }

        if (a[0] > a[1]) cout << a[1] << " " << a[0] << endl;
        else cout << a[0] << " " << a[1] << endl;
    }

    return 0;
}
