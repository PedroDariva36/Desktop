#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll sum = 0;

        cin >> n;
        vector<long> a(n+n);
        
        for (int i = 0; i < n+n; i++) cin >> a[i];
        
        sort(a.begin(),a.end());

        for(int i = 0; i < n+n; i +=2){
            sum += min(a[i], a[i+1]);
        }

        cout << sum << endl;

    }


    return 0;
}
