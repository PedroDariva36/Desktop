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
    int n;
    
    ll g[6][6] = {0};

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++)
            cin >> g[i][j];
    } 
    
   
    ll sum = 0;

    vector<int> a;
    for (int i = 0; i < 6; i++) a.pb(i);
    for (int i = 0; i < 6; i++) sum += g[i][a[i]];


    while (next_permutation(all(a))) {
        ll aux = 0; 
        for (int i = 0; i < 6; i++) aux += g[i][a[i]];
        sum = max(sum, aux);
    }

    
    cout << sum << endl;


    return 0;
}
