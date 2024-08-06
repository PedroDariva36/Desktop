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
    
    string pi = "314159265358979323846264338327";
    int tt;
    cin >> tt;
    string s; 
    while (tt--) {
        cin >> s;  
        ll c = 0;
        for (int i = 0; i < s.size(); i++) {
            if(pi[i] != s[i]) break;
            c++;
        } 

        cout << c << endl;

        
         

    }
    return 0;
}
