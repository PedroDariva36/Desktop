#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;


int memo[21][31];
int solve(int w, vector<pair<int,int>> &c, int n){
    if(n == 0 or w == 0)
        return 0;
    
    if (memo[n][w] != -1) return memo[n][w];


    if(c[n-1].second > w){ 
        memo[n][w] = solve(w, c, n-1);
        return memo[n][w];
    }
            
    memo[n][w] = max(
        c[n-1].first + solve(w - c[n-1].second, c, n-1),
        solve(w, c, n-1)
    );
    return memo[n][w]; 

}

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n, p;
    while (cin >> n >> p) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= p; j++)
                memo[i][j] = -1;
        }
        vector<pair<int,int>> c(n);
        for (auto &i : c) 
            cin >> i.first >> i.second; 
        cout << solve(p, c, n) << " min." << endl;
    }

    return 0;
}
