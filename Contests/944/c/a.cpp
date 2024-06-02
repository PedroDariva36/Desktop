#include <bits/stdc++.h>
#include <utility>
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
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        
        if (a > b) swap(a,b);

        if (c > a && c < b && (d < a || d > b)) {
            cout << "YES" << endl;
            continue;
        }
        swap(c,d);
        if (c > a && c < b && (d < a || d > b)) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;




    }

    return 0;
}
