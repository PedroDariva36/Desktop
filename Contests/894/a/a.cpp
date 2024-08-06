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
        int n, m;
        cin >> n >> m;
   

        map<char,char> k;
        k['v'] = 'i';
        k['i'] = 'k';
        k['k'] = 'a';
        k['a'] = '!';
        k['!'] = '!';

        char a[n][m];

        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) 
                cin >> a[i][j];
        } 

        bool f = 0; 
        
        char last = 'v'; 
        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(a[i][j] == last){
                    last = k[last];
                    break;
                }    
            }
            if(last == '!') f = 1;
        }
        */
        last = 'v';
        for (int j = 0; j < m; j++) {

            for (int i = 0; i < n; i++) {
                if(a[i][j] == last){
                    last = k[last];
                    break;
                }    
            }
            if(last == '!') f = 1;
        }
        
        cout << (f? "YES":"NO") << endl;



         

    }
    return 0;
}
