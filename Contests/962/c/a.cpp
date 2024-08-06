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
        int n, q;
        cin >> n >> q;
  
        vector<char> a(n);
        vector<char> b(n);
        
        vector<array<int,26>> prefa, prefb;

        for (auto &i : a) cin >> i;         
        for (auto &i : b) cin >> i;        
    

        
        array<int, 26> aux;
        for (int i = 0; i < n; i++) {
            aux[a[i]-'a']++; 
            prefa.pb(aux);
        }
        for (auto &i : aux) i=0;
        
        for (int i = 0; i < n; i++) {
            aux[b[i]-'a']++; 
            prefb.pb(aux);
        }
    
        
        int x, y;
        while (q--) {
            cin >> x >> y;
            x--;y--;
        
            array<int, 26> ac,bc;
            
            for (int i = 0; i < 26; i++) {
                ac[i] = prefa[y][i] - prefa[x][i];
            }
            ac[a[x]-'a']++; 

            for (int i = 0; i < 26; i++) {
                bc[i] = prefb[y][i] - prefb[x][i];
            }
            bc[b[x]-'a']++;
                
            ll sum = 0; 
            for (int i = 0; i < 26; i++) {
                sum += abs(ac[i] - bc[i]);
            } 
            sum >>= 1;
            cout << sum << endl;

        }


        
         

    }
    return 0;
}
