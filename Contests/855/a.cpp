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
        bool f = 1;
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

        if(n >= 2*k) {
            cout << "YES" << endl;
            continue;
        } 

        cout << "NO" << endl;

        
         

    }
    return 0;
}
