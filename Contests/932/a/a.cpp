#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        string s, rs;
        cin >> n;
        cin >> s;
        
        rs = s;
        reverse(s.begin(),s.end());

        if (s.compare(rs) > 0) {
            cout << n << endl;
            if (n % 2 == 0) {
                cout << s << endl;
            }
            else {
                cout <<s << rs << endl;
            }

        }
        else {
            if ((n-1)%2 == 0) {
                cout << rs << endl;
            }
            else {
                cout <<rs << s << endl;
            }

        }


    }

    return 0;
}
