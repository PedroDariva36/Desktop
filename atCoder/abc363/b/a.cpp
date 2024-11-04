#include <algorithm>
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
    int n, t, p;
    cin >> n >> t >> p;

    vector<int> a(n);
    for (auto &i: a) 
        cin >> i;
    
    ll sum = 0;
    int mx = -1;
    vector<int> b; 
    for (int i = 0; i < n; i++) {
        if(a[i] < t){
            b.pb(t-a[i]);
        }
        else b.pb(0);
    }
    sort(all(b));
    cout << b[p-1]<< endl;


    return 0;
}
