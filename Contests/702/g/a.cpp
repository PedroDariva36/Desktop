#include <bits/stdc++.h>
#include <iostream>
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
        int n, m;
        ll st = 0; 
        cin >> n >> m;
        vector<ll> a(n), x(m), p;


        for (auto &i: a) {
            cin >> i;
            st += i;
            p.push_back(st);
        }
        for (auto &i: x) cin >> i;


        for (auto i: x) {

            ll t = abs(i/p.back());            
            ll sum = t*p.back();

            bool f = false;
            ll pos = t*n;
            for (int k = 0; k < n; k++) {
                if(p[k] == i - sum){
                    pos += k;
                    f = true;
                    break;
                } 
            }
                
            cout << pos << " ";
            //cout <<(f?pos:-1) << " "; 



        }
        cout << endl;    
    }
    return 0;
}
