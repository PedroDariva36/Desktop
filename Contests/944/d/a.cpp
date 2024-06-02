#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        int c = 1;
        char last = s[0];
        int k = 1;
        bool f = false;
        while (k < s.size()) {
            if (s[k] == last) {
                k++;
                continue;
            }
            
            if (last == '0' && !f) {
                f = true;
                last = s[k]; 
                k++;
                continue;
            }

            last = s[k];
            c++; 
            k++;
        }
        
        cout << c << endl;

    }

    return 0;
}
