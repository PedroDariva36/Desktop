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
    cin >> n;
    vector<ll> a(n);    
        
    for (auto &i : a) {
        cin >> i;    
    }
   
    map<int,int> m;
    for (int i = 0; i < n; i++) {
        m[a[i]] = i;
    } 




    sort(rall(a));
    cout <<  m[a[1]]+1 << endl;




    return 0;
}
