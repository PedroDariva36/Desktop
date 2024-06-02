#include <bits/stdc++.h>
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
        int n,m;
        char aux;
        cin >> n >> m;
        int g[n][m]; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> aux;
                if (aux == 'W') g[i][j] = 1;
                else g[i][j] = 0;
            }
        }

        if (n == 1) {
            if (g[0][0] == g[0][m-1]) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
            continue;
        }
        
        if (m == 1) {
            if (g[0][0] == g[n-1][0]) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
            continue;
        }
         

        if(n == m){
            if (g[0][0] == g[n-1][m-1] || g[0][m-1] == g[n-1][0]) {
                cout << "YES" << endl;
                continue;
            }
        }
        //ok
        if (g[0][0] == g[0][m-1]) {
            int i = 0;
            for (i = 1; i < m-1; i++) {
                if (g[n-1][i] == g[0][0]) break;
            }

            if (g[n-1][i] == g[0][0]) {
                cout << "YES" << endl;
                continue;
            }
        }
        
        //ok
        if (g[n-1][0] == g[n-1][m-1]) {
            int i = 0;
            for (i = 1; i < m-1; i++) {
                if (g[0][i] == g[n-1][0]) break;
            }

            if (g[0][i] == g[n-1][0]) {
                cout << "YES" << endl;
                continue;
            }
        }

        //ok
        if (g[0][m-1] == g[n-1][m-1]) {
            int i = 0;
            for (i = 1; i < n-1; i++) {
                if (g[i][0] == g[0][m-1]) break;
            }

            if (g[i][0] == g[0][m-1]) {
                cout << "YES" << endl;
                continue;
            }
        }

        if (g[0][0] == g[n-1][0]) {
            int i = 0;
            for (i = 1; i < n-1; i++) {
                if (g[i][m-1] == g[0][0]) break;
            }

            if (g[i][m-1] == g[0][0]) {
                cout << "YES" << endl;
                continue;
            }
        }

        cout << "NO" << endl;




    }

    return 0;
}
