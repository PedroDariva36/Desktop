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
        int n, m;
        cin >> n >> m;

        char g[n][m];
        char aux;
        int mx = 0;
        int pos = -1;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                cin >> aux; 
                g[i][j] = aux;
                if(aux == '#') sum++;
            }
            if(sum > mx){
                pos = i;
                mx = sum;
            }
        }
        int start = -1;
        int stop = -1;
        for (auto i = 0; i < m; i++) {
            if(g[pos][i] == '#'){
                if(start == -1){
                    start = i;
                }
                stop = i;
            }
        }
        cout << pos+1 << " " << (start + stop)/2+1 << endl;;         

    }

    return 0;
}
