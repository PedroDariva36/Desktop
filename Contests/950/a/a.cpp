#include <bits/stdc++.h>
#include <map>
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
        int n, k;
        char aux;
        cin >> n >> k;
        map<char, int> m;
        m['A'] = 0;
        m['B'] = 0;
        m['C'] = 0;
        m['D'] = 0;
        m['E'] = 0;
        m['F'] = 0;
        m['G'] = 0;
        ll sum = 0;

        for (int i = 0; i < n ;i++) {
            cin >> aux;
            m[aux]++;
        }
    
        for (auto &i : m) {
            if (k <= i.second) continue;
            sum += k - i.second;
        }

        cout << sum << endl;


    }

    return 0;
}
