#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

ll solve(int k,vector<ll> &a){
    if (k == -1)
        return 0;

    ll m = max(solve(k-1, a)+a[k], abs(solve(k-1,a)+a[k]));
    return m;
}





int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        vector<ll> b;

        b.push_back(a[0]);
        int c = (a[0] > 0);

        for (int i = 1; i < n; i++) {
            if((a[i] > 0) != c){
                c = !c;
                b.pb(a[i]);
            }
            else b.back() += a[i];
        }
        /*
        for (auto i: b) {
            cout << i << " ";
        }
        cout << endl;
        */



        


        cout << solve(b.size()-1, b) << endl;;

        //long m[n][n] = {0};

        




        


    }

    return 0;
}
