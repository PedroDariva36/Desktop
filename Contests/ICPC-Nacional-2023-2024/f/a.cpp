#include <bits/stdc++.h>
#include <cmath>
#include <ios>
#include <stack>
#define ll long long

using namespace std;

bool solve(ll n, ll b){
    vector<ll> s;
    stack<ll> t; 
    
    while (n > 0) {
        s.push_back(n%b);
        n /= b;
    }
    for (auto i : s) t.push(i);

    for (auto i : s) {
        if (i == t.top()) t.pop();
        else return false;
    }
    return true;

}

int main (int argc, char *argv[]){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


//    cout << solve(33, 32) << endl;
//    cout << solve(33, 33) << endl;
//    cout << solve(33, 10) << endl;
//    cout << solve(33, 2) << endl;
    bool flag = 0;
    ll n;
    cin >> n;

    ll s = sqrt(n-1);
    for (ll i = 2; i <= s; i++) 
        if(solve(n,i)){ 
            cout << i << " ";
            flag = true;
        }

    for (ll i = sqrt(n+1)-1; i > 0; i--) {
        if(n % i == 0){
            cout << n/i -1 << " ";
            flag = true;
        }
    }
    
    if (flag == 0) cout << "*";
    cout << endl;



    return 0;
}
