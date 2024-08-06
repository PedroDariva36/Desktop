#include <bits/stdc++.h>
#include <vector>
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
        int n, m , k;
        cin >> n >> m >> k;
    
        vector<char> a;
        char aux;   
        a.pb('L');
        for (int i = 0; i < n; i++) {
            cin >> aux;
            a.push_back(aux);
        }
        a.pb('L');               

        int pos = 0;
        while(pos != n+1){
            if(a[pos] == 'L'){
                bool g = 0; 
                int w = pos;
                for (int i = pos+1; i <= pos + m; i++) {
                    if(a[i] == 'W') w = i;
                    if(a[i] == 'L'){
                        g = 1; 
                        pos = i;
                        break;
                    }
                }
                if(g) continue;
                if(w == pos) break; 
                pos = w; 
            }

            if(a[pos] == 'W'){
                bool g = 0;
                for (int i = pos+1; i <= pos + k; i++) {
                    if(a[i] == 'C') break;
                    if(a[i] == 'L'){
                        g = 1;
                        k -= i - pos; 
                        pos = i;
                        break;
                    }
                }
                
                if(g) continue;
                else break;
            }
        }
        
        cout << (pos == n+1?  "YES": "NO") << endl;
         

    }
    return 0;
}
