#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    ll c, n; 
    cin >> c >> n;

    if (c > (n/2)) {
        cout << "1" << endl;
    }
    else {
        cout << "0" << endl;
    }



    return 0;
}
