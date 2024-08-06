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
    
            
        for (char i = 'a'; i <= 'h'; i++) {
            if(i == s[0]) continue; 
            cout << i << s[1] << endl;
        }
        
        for (int i = 1; i <= 8; i++) {
            if(i == (s[1]-'0')) continue; 
            cout << s[0] << i << endl;
        }



         

    }
    return 0;
}
