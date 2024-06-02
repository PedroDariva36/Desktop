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
        int a,b,c;
        cin >> a >> b >> c;
         ll sum = 0; 
        

        while (true) {
            if (b > c) swap(b,c); 
            if (a > c) swap(a,c);
            if (a > b) swap(a,b); 
            if (c < 1 || b < 1) break;
            b--;
            c--;
            sum += 1;
        }
       
        
        if (c%2 == 1) {
            cout << -1 << endl;
            continue;
        }

        cout << sum << endl;

    }

    return 0;
}
