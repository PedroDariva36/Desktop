#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &i : a) cin >> i;

        ll asw = 0;
        bool f = false; 
        
        for (int i = 0; i < n; i++) {
            ll sum = 0;     
            for (auto j: a) if(j > i) sum++;
            
            if(i == sum){
                f = 1;
                asw = i;
                break;
            }

        }
        cout << (f? asw : -1) << endl;

    }
    return 0;
}
