#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <tuple>
#include <utility>
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
        const int INF = 2*1e5;
        int n; int k;
        long aux;
        cin >> n >> k;
        
        vector<int> a(n+1);
        int dp[k+1][n+1];
        
        for (int i = 0; i < k+1; i++) {
            for (int j = 0; j < n+1; j++) {
                dp[i][j] = INF;
            } 
        }
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            cin >> a[i]; 
        }

        for (int r = 1; r <= n; r++) {
            int m = INF;
            for (int i = 1; i-1 <= k && i <= r; i++) {
                m = min(m, a[r-i+1]);
                for(int j = 0; j + i -1 <= k; j++){
                    dp[j+i-1][r] = min(dp[j+i-1][r],m*i+dp[j][r-i]);
                }
            }
        }

        int m = INF;
        for (int i = 0; i <= k; i++) {
            m = min(m, dp[i][n]); 
        }
        
        cout << m << endl;


    }

    return 0;
}
