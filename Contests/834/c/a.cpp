#include <bits/stdc++.h>
#include <utility>
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
        ll l , r, x;
        ll a, b;

        cin >> l >> r >> x >> a >> b;
        if(a == b){
            cout << 0 << endl;
            continue; 
        } 
        if(abs(a-b) >= x){
            cout << 1 << endl;
            continue; 
        }
    
        if(abs(l-a) < x && abs(r-a) < x ){
            cout << -1 << endl;
            continue; 
        }
        
        if(abs(l-b) < x && abs(r-b) < x ){
            cout << -1 << endl;
            continue; 
        } 


        if(a > b) swap(a,b);
        if(abs(l-a) >= x && abs(l-b) >= x || abs(r-a) >= x && abs(r-b) >= x){
            cout << 2 << endl;
            continue;
        }
    
        cout << 3 << endl;






    }
    return 0;
}
