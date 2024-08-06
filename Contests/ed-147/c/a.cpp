#include <bits/stdc++.h>
#include <map>
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
        string s,t;
        cin >> s; 
        map<char, int> m; 
        for (auto i: s) m[i]++;  

        if(m.size() == 1){
            cout << 0 << endl;
            continue;
        }
        /* 
        if(m.size() == s.size()){
            ll sum = 0;
            ll k = s.size(); 
            while (k > 1) {
                sum++;
                k>>=1;
            } 
            cout << sum << endl;;
            continue;
        }
    
        */


        ll asw = s.size();
        for (auto k: m) {
            char aux = k.first;



            vector<char> a,b;
            for (int i = 0; i < s.size(); i++) a.pb(s[i]);

            ll sum = 0; 
            while(a.size() != k.second){ 
                //cout << a.size() << endl; 
                sum++; 
                bool ad = 0;
                for (auto i = 0; i < a.size(); i++) {
                    if(a[i] == aux) {
                        b.pb(a[i]);
                        ad = 0;
                        continue;
                    }
                    if(ad == 0){
                        ad = 1;
                        continue;
                    }
                    b.pb(a[i]);
                    ad = 0;
                }
                a = b;
                b.clear();
            }
            asw = min(asw, sum);   
        } 
        cout << asw << endl; 

    }
    return 0;
}
