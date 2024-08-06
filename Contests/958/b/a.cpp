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
        vector<int> a(n);
        char aux;
        for(auto &i: a){
            cin >> aux;
            i = aux - '0';
        }
        vector<int> b;
        bool f = 0;
        for (int i = 0; i < n; i++) {
            if(a[i] == 0 && f) continue; 
            if(a[i] == 0 && !f){
                b.pb(a[i]);
                f = 1;
            }
            if(a[i] == 1){  
                b.pb(a[i]);
                f = 0;
            }
        }    

        ll c1 = 0, c0 = 0;
        for(auto &i: b){
            if(i == 0) c0++;
            else c1++;
        }         
    
        cout << (c1 > c0? "Yes":"No") << endl;


    }
    return 0;
}
