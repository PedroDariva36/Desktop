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
        cin >> n;
        
        vector<char> s(n);
        vector<int> a(n);
    
        for (auto &i: a) cin >> i;
        for (auto &i: s) cin >> i;
    
        vector<int> m(51,-1);
        set<int> st;
        bool f = 1;        
        
        for (int i = 0; i < n; i++) {
            if(m[a[i]] == -1){
           
                m[a[i]] = int(s[i]-'a');
                continue; 
            }

            if(m[a[i]] != (int)(s[i]-'a')){
                f = 0;
                break;
            }

        }
        
        cout << (f?"YES":"NO") << endl;

         

    }
    return 0;
}
