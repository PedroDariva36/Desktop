#include <algorithm>
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
        vector<ll> a; 
        string s;
        cin >> s;
        bool f = 0;
        ll k;
        for (int i = s.size()-1; i >= 0; i--) {
            if(s[i]-'0' >= 5) {
                f = 1;
                k = i;
            }
            a.pb(s[i]-'0'); 
        }
        if(f){ 
            for (int i = 0; i < a.size()-1; i++) {
                if(a[i] >= 5){
                    a[i] = 0;
                    a[i+1]++;
                } 
                else if(i < a.size()-k)
                    a[i]  = 0;
                else 
                    break;
            }

            if(a.back() >= 5){
                ll aux = a.back(); 
                a[a.size() -1] = 0;
                a.pb(1);
            }



        }
        
        reverse(all(a));
        for (auto i: a) {
            cout << i;
        }
        cout << endl;


         

    }
    return 0;
}
