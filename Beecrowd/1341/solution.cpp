// 1341

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void le_caminho_crianca(vector<string> &grade, string &s) {
    int n;
    int x;
    int y;
    cin >> n >> x >> y;
    x--;
    y--;

    s.push_back(grade[x][y]);

    char mov;
    for (int i = 0; i < n; i++) {
        cin >> mov;
        if (mov == 'N') {
            x--;
        }
        else if (mov == 'E') {
            y++;
        }
        else if (mov == 'S') {
            x++;
        }
        else { // mov == 'O'
            y--;
        }

        s.push_back(grade[x][y]);
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num_testes;
    cin >> num_testes;

    for (int t = 1; t <= num_testes; t++) {
        int h;
        int w;
        cin >> h >> w;

        vector<string> grade(h);
        for (auto &linha : grade) {
            cin >> linha;
        }

        string s_a(1, '\0');
        le_caminho_crianca(grade, s_a);

        string s_b(1, '\0');
        le_caminho_crianca(grade, s_b);

        int ult_ind_a = s_a.size();
        int ult_ind_b = s_b.size();

        vector<vi> memo(ult_ind_a + 1, vi(ult_ind_b + 1));

        for (int i = 0; i <= ult_ind_a; i++) {
            memo[i][0] = 0;
        }

        for (int i = 1; i <= ult_ind_b; i++) {
            memo[0][i] = 0;
        }

        for (int i = 1; i <= ult_ind_a; i++) {
            for (int j = 1; j <= ult_ind_b; j++) {
                if (s_a[i] == s_b[j]) {
                    memo[i][j] = memo[i - 1][j - 1] + 1;
                }
                else {
                    memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
                }
            }
        }

        cout << "Case " << t << ": " <<
            (ult_ind_a - memo[ult_ind_a][ult_ind_b]) << " " <<
            (ult_ind_b - memo[ult_ind_a][ult_ind_b]) << "\n";
    }

    return 0;
}

