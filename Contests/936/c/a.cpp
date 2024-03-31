#include <bits/stdc++.h>
#include <vector>
#define ll long long


using namespace std;

bool solve(int x, vector<vector<int>> &a){
     

    return true;
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        int x,y;
        cin >> n >> k;
        n--;
        vector<vector<int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> x >> y; 
            a[x-1].push_back(y-1);
            a[y-1].push_back(x-1);
        }
        int l = 1, r = n/k + 1;
        while (r-l > 1) {
            int mid = (r-l)/2;
            (solve(mid, a)? l = mid : r = mid);
        }
        cout << l << endl;
    }

    return 0;
}
