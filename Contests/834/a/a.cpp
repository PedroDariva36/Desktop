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
        string s;
        cin >> s;
        map<char,char> m;
        m['Y'] = 'e';
        m['e'] = 's';
        m['s'] = 'Y';

        if(s[0] != 'Y' && s[0] != 'e' && s[0] != 's'){
            cout << "NO" << endl;
            continue;
        }

        bool f = 1;
        for (int i = 0; i < (int)s.size() - 1; i++) {
            if(m[s[i]] != s[i+1]){
                f = 0;
                break;
            }
        } 
        
        cout << (f?"YES":"NO") << endl;


        
         

    }
    return 0;
}
