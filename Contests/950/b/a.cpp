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
    int t;
    cin >> t;
    while (t--) {
        int n, f, k;
        cin >> n >> f >> k;
        

        int pref = -1;
        vector<int> a(n);
        
        for (auto &i : a) cin >> i;
        pref = a[f-1];
        

        bool l = false, r = false;
        sort(rall(a));
            

        for (int i = 0; i < k; i++) {
            if (a[i] == pref) l = true;
        }

        for (int i = k; i < n; i++) {
            if (a[i] == pref) r = true;
        }

        if(r & l)
            cout << "MAYBE";
        else if(r & !l)
            cout << "NO";
        else cout << "YES";
        cout << endl;

    }

    return 0;
}
