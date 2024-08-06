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
        int n,m;
        cin >> n >> m;
    
        char aux;
        int a[n][m], b[n][m];
    
        ll c1 = 0, c2 = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> aux;
                a[i][j] = aux - '0';
            }    
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> aux;
                b[i][j] = (int)(aux - '0');
            }    
        }
        bool f = 1;

        for (int i = 0; i < n; i++) {
            int c1 = 0, c2 = 0; 
            for (int j = 0; j < m; j++) {
                c1 += a[i][j];
                c2 += b[i][j];
            }
            if((c1 % 3) != (c2 %3)) f= 0;
        } 
        for (int j = 0; j < m; j++) {
            int c1 = 0, c2 = 0; 
            for (int i = 0; i < n; i++) {
                c1 += a[i][j];
                c2 += b[i][j];
            }
            if((c1 % 3) != (c2 %3)) f= 0;
        } 
         

            
        cout << (f?"YES":"NO") << endl;
         

    }
    return 0;
}
