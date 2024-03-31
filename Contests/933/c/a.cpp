#include <bits/stdc++.h>
#include <set>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        ll sum = 0;
        for (int i = 0; i < n-2; i++) {
            if (s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e') {
                sum++;
                i+=2;
                continue;
            }
            if (s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p'){
                sum++;
                i+=2;
                continue;
            }
        } 
        cout << sum << endl;

    }

    return 0;
}
