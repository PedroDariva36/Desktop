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
        int n;
        char l;
        cin >> n >> l;
    
       
        char aux;
        vector<char> s;
        vector<int> d(n,n+1);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            s.push_back(aux);
            if(aux == 'g') q.push(i);    
        } 
        
        while (!q.empty()) {
            int c = q.front(); q.pop();
            int k = 0; 
            while (d[c] == n+1) {
                if(s[c] == 'g') k = 0;
                d[c] = k++;      
                c = ((c-1)%n + n)%n;
            }
        }

         
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if(s[i] == l){
                mx = max(d[i],mx);
            } 
        }
        cout << mx << endl;

        


         

    }
    return 0;
}
