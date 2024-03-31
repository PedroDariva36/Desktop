#include <bits/stdc++.h>
using namespace std;

string getSt(vector<string> &m) {
    int n, x, y;
    string a;
    cin >> n >> x >> y;
    x--; y--;

    a.push_back(m[x][y]);

    char mov;
    for (int i = 0; i < n; i++) {
        cin >> mov;
        if (mov == 'N') x--;
        else if (mov == 'E') y++;
        else if (mov == 'S') x++;
        else y--;
        a.push_back(m[x][y]);
    }

    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, h , w;
    cin >> t;

    while(t--) {
        cin >> h >> w;

        vector<string> m(h);
        for (auto &s : m)
            cin >> s;

        string a = string(1,'\0');
        a = getSt(m);
        string b = string(1,'\0');
        b = getSt(m);

        vector<vector<int>> memo(a.size() + 1, vector<int>(b.size() + 1));

        for (int i = 0; i <= a.size(); i++) memo[i][0] = 0;
        for (int i = 1; i <= b.size(); i++) memo[0][i] = 0;


        for (int i = 1; i <= a.size(); i++) {
            for (int j = 1; j <= b.size(); j++) {
                if (a[i] == b[j]) memo[i][j] = memo[i - 1][j - 1] + 1;
                else memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
            }
        }

        cout << "Case " << t << ": " << a.size() - memo[a.size()][b.size()] << " " << b.size() - memo[a.size()][b.size()] << endl;
    }

    return 0;
}

