#include <bits/stdc++.h>
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
        ll a, b;
        ll fa, fb;
        
        cin >> a >> b;
        cin >> fa >> fb;
        
        if(a < b){
            swap(a, b);
            swap(fa,fb);
        }


    
        if(a >= b && fa >= fb){
            cout << "YES" << endl;; 
        }
        else {
            cout << "NO" << endl;;
        }


        
         

    }
    return 0;
}
