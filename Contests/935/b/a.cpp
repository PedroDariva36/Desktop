#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b , m;
        cin >> a >> b >> m;
        
        ll sum = 0;
        m++;
        
        sum += m/a;
        if (m%a > 0) {
            sum++;
        }
        sum += m/b;
        if (m%b > 0) {
            sum++;
        }
        cout << sum << endl;



    }

    return 0;
}
