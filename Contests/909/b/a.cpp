#include <bits/stdc++.h>
#include <climits>
#include <vector>
#define ll long long
using namespace std;


ll solve(vector<ll> &a, int k, int n){
    ll mn=1e18, mx = -1e18;
    ll sum;
    for(int i = 0; i + k <= n; i += k){
        sum = 0;
        for(int j = i; j < i+k; j++){ 
            sum += a[j];
        }
        mn = min(mn, sum); 
        mx = max(mx, sum);
    }
    return mx - mn;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll dif = 0;
        for(int i = 1; i * i <= n; i++){
            if(n%i == 0){
                dif = max(dif, solve(a,i,n));
                if(n/i != i)
                    dif = max(dif, solve(a,n/i,n));   
            }
        }
        cout << dif << endl;

    }


    return 0;
}

