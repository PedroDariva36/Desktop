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
        string s;
        cin >> s; 
        int i; 
        for (i = 0; i < s.size()-1; i++) {
            if(s[i] == s[i+1]) break;                
        }
        vector<char> a; 
        for (int j = 0; j <= i; j++) {
            a.pb(s[j]);
        }
        int k = a[i] - 'a';
        k = (k+1)%26;
        a.pb('a'+k); 
        for (int j = i+1; j < s.size(); j++) {
            a.pb(s[j]); 
        }
    
        for (auto &i : a) {
            cout << i; 
        }
        cout <<endl;



    }
    return 0;
}
