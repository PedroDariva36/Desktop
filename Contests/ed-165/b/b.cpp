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
        int size = 0;
        ll sum = 0;
        for (auto i: s) {
            if (i == '1') {
                size++;
            } 
            else {
                if (size != 0)sum += (size+1);
            }
        }
        cout << sum << endl;
    }

    return 0;
}
