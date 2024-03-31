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
        cin >> n;
        vector<ll>a(n);
        
        for (auto &i: a) {
            cin >> i; 
        }
        
        sort(a.begin(),a.end());
        
        cout << abs(a[0] - a[n-2]) + abs(a[n-2] - a[1]) + abs(a[1] - a[n-1]) + abs(a[n-1] - a[0]) << endl;
        


    }

    return 0;
}
