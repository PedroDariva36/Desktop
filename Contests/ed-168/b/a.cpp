#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        char g[2][n];
    
        for (int i = 0; i < n; i++) {
            cin >> g[0][i];
        }
        for (int i = 0; i < n; i++) {
            cin >> g[1][i];
        }

        ll sum = 0;
        for (int i = 0; i < n-2; i++) {
            if(g[0][i] == 'x' && g[0][i+1] == '.' && g[0][i+2] == 'x')
                if(g[1][i] == g[1][i+1] && g[1][i+1] == g[1][i+2] && g[1][i+1] == '.') sum++; 

            if(g[1][i] == 'x' && g[1][i+1] == '.' && g[1][i+2] == 'x')
                if(g[0][i] == g[0][i+1] && g[0][i+1] == g[0][i+2] && g[0][i+1] == '.') sum++; 

        }    

        cout << sum << endl;


    }
    return 0;
}
