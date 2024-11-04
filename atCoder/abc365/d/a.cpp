#include <algorithm>
#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

int n;
string s;
const int N = 2*1e5+10;
int memo[N][3];

int p(char i, int j) {
    if (i == 'S' && j == 0) {
        return 1;
    } else if (i == 'R' && j == 1) {
        return 1;
    } else if (i == 'P' && j == 2) {
        return 1;
    }

    return 0;
}

int solve(int i, int u) {
    if (i == n) {
        return 0;
    }

    if (u != -1 && memo[i][u] != -1) {
        return memo[i][u];
    }

    int ans = 0;
    if (u != 0 && s[i] != 'P')
        ans = solve(i+1, 0) + p(s[i], 0);

    if (u != 1 && s[i] != 'S') 
        ans = max(ans, solve(i+1, 1) + p(s[i], 1));

    if (u != 2 && s[i] != 'R') 
        ans = max(ans, solve(i+1, 2) + p(s[i], 2));

    memo[i][u] = ans;
    return ans;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cin >> s; 
    memset(memo, -1, sizeof(memo));  
    cout << (solve(0,-1)) << endl;
    return 0;
}
