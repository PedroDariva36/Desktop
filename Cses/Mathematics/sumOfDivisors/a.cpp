#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;
const ll m = 1e9+7;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> d;
    for (ll i = 1; i <= (ll)sqrt(n); i++) {
        if (n%i == 0) {
            d.push_back(i);
            if(n/i != i) d.push_back(n/i);
        } 
    }
    ll last = 0;  
    sort(all(d));  
    for (auto i : d) {

        sum = (sum + ((n/i)%m * abs(i-last+1)%m)%m)%m;
        last = i;
    }
    

    cout << sum << endl;

    return 0;
}
