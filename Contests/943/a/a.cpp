#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
        int n;
        cin >> n;
        int mx = 0;
        int k = 1;
        for (int i = 1; i < n; i++) {
            if(mx < (gcd(i, n) + i)){
                k = i;
                mx = (gcd(i, n) + i);
            } 
        }


        cout << k << endl;


    }

    return 0;
}
