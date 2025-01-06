#include <bits/stdc++.h>
#include <bitset>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll n,m;
        cin >> n >> m;
   

        bitset<64> k = n;
        bitset<64> l = max(0ll,n-m);
        bitset<64> r = n+m; 
    
        bool f = 1;
        for(int i = 63; i >= 0; i--){
            if(f && k[i] == l[i]) continue;
            f=0; 
            k[i] = 1;
        }        
        f = 1;
        for(int i = 63; i >= 0; i--){
            if(f && k[i] == r[i]) continue;
            f=0; 
            k[i] = 1;
        }
    
        n = k.to_ullong();
        cout << n << endl; 




    }

    return 0;
}
