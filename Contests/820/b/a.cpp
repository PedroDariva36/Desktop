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

    vector<char> m;
    m.pb('-');     
    for (char i = 'a'; i <= 'z'; i++) m.pb(i);

    while (tt--) {

        int n;
        cin >> n;
        vector<char> a(n);
        for(auto &i: a) cin >> i;        
        reverse(all(a));
        vector<char> f;
        for (int i = 0; i < n; i++) {
            if(a[i] == '0'){
                f.pb(m[((a[i+1]-'0') + 10*(a[i+2]-'0'))]);
                i+=2;
                continue;
            }
            f.pb(m[a[i]-'0']);
        }

        reverse(all(f));       
    
        for(auto &i: f)
            cout << i;
        cout << endl;
        



    }
    return 0;
}
