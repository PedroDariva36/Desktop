#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(ll k, vector<long> &a, ll p){
    ll sum = 0; 
    for (auto &i: a) sum += k/i; 
    return (sum >= p);
}

int main (int argc, char *argv[]){
    int n;
    ll p;

    cin >> n >> p;
    vector<long> a(n);
    for (auto &i : a)
        cin >> i;

    ll l = 0;
    ll r = 1e17;
    ll mid;
    while (l < r) {
        mid = (l + r)/2;
        if (solve(mid, a, p)) 
            r = mid;
        else 
            l = mid + 1;
    } 
    cout << l << endl;

    return 0;
}
