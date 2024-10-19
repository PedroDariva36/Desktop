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
    

        ll sum = 0;
        vector<ll> p(n);
        string s; 
        vector<ll> k(n);

        cin >> s;
        for(auto &i: p) {
            cin >> i;
            i--;
        }


        for (int i = 0; i < n ; i++) {
            ll l = 0; 
            string a = s;
            string b;
            do{
                b = a;
                a.clear();
                for(int j = 0; j < n; j++){
                    a.pb(b[p[j]]);
                }
                l++;

            } while (a[i] != s[i]);
            k[i] = l;
        }

        ll l = 1;
        for (int i = 0; i < n; i++) {
            //cout << k[i] << " ";
            l = lcm(l,k[i]);
        }
        //cout << endl;
        cout << l << endl;

    }
    return 0;
}
