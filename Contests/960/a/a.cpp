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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &i: a) cin >> i;

        int mx = *max_element(all(a));
        int c =0;

        for (int i =0; i < n; i++) {
            if(a[i] == mx) c++;
        }
    
        if(c % 2 == 0){
            bool f = 0;
            map<int,int> m;
            for (auto i :a) {
                m[i]++;
            }
            for (auto i: m) {
                if(i.second%2 == 1) f = 1;
            }
            
            if(f){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;





        }
        else cout << "YES" << endl;

    
    




         

    }
    return 0;
}
