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
        char aux;
        map<char, int> m;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            m[aux]++;
        } 
        if(n != 5 || m.size() != 5){
            cout << "NO" << endl; 
            continue; 
        }        
        bool f = 1;
        if(m['T'] != 1)  f = 0;
        if(m['i'] != 1)  f = 0;
        if(m['m'] != 1)  f = 0;
        if(m['u'] != 1)  f = 0;
        if(m['r'] != 1)  f = 0;


        cout << (f?"YES":"NO") << endl;
          
         
    


    }
    return 0;
}
