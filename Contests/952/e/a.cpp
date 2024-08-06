#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;


ll solve(ll a, ll b,ll c, ll x, ll y, ll z){
    return (a+1-x)*(b+1-y)*(c+1-z);
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll a,b,c;
        ll w;
        cin >> a >> b >> c >> w;

        ll sum = 0; 
        for (auto i = 1; i <= a; i++) {
            for (auto j = 1; j <= b; j++) {
                if(w%(i*j) == 0)
                    sum = max(solve(a,b,c,i,j,w/(i*j)),sum);
            }
        }
        cout << sum << endl;

    } 

    return 0;
}
