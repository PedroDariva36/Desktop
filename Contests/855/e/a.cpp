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
        int n, k;
        cin >> n >> k;
        vector<char> s(n);
        vector<char> t(n);

        for(auto &i: s) cin >> i;
        for(auto &i: t) cin >> i;
        bool f = 1; 

        if(n <= k){
            for (int i = 0; i < n; i++) {
                if(s[i] != t[i]){
                    f = 0; break;
                } 
            }
            if(f){
                cout << "YES" << endl;
                continue;
            }
        }

        {
            map<char, int> a, b;
            for (int i = 0; i < n; i++) {
                a[s[i]]++;
                b[t[i]]++;
            }

            for (char i = 'a'; i <= 'z'; i++) {
                if(a[i] != b[i]){
                    f = 0;
                    break;
                } 
            }
        }

        if(!f){
            cout << "NO" << endl;
            continue;
        }


        if(n < 2*k){
            map<char, int> a, b;

            for (int i = 0; i < n; i++) {
                if(n-k <= i && i <= k-1 ){
                    if(s[i] != t[i]){
                        f = 0; 
                        break;
                    }
                }
                a[s[i]]++;
                b[t[i]]++;
            }

            for (char i = 'a'; i <= 'z'; i++) {
                if(a[i] != b[i]){
                    f = 0;
                    break;
                } 
            }

        }

        cout << (f?"YES":"NO") << endl;




    }
    return 0;
}
