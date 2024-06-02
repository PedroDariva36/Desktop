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
        int n,aux;
        cin >> n;
        vector<int> a(n);
        vector<int> b;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int k = a[0];
        int c = 1; 
        for (int i = 1; i < n; i++) {
            if (a[i] == k) {
                c++;
                continue;
            }
            else {
                b.push_back(c);
                c = 0;
            }
        }
        b.push_back(c);
        if (b.size() == 1) {
            cout << -1 << endl; 
            continue; 
        }

        int r = *(min_element(all(b)));
        cout << r << endl;
        
    }

    return 0;
}
