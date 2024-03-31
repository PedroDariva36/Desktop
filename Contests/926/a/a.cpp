#include <algorithm>
#include <bits/stdc++.h>
#include <unistd.h>
#include <vector>
#define ll long long


using namespace std;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<long> a(n);
        for (int i = 0; i < n ; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        
        ll sum = 0;
        for (int i = 1; i < n; i++) {
            sum += a[i] - a[i-1];
        }
        cout << sum << endl;

    }
    return 0;
}
