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
    

        vector<int>a;
        for (int i = 9;i > 0; i--) {
            if(n == 0) break;
            if(i >= n){
                a.pb(n);
                break;
            }
            if(n > i){
                a.pb(i);
                n-=i;
            }

        }

        reverse(all(a));
        for(auto i: a){
            cout << i;
        }
        cout << endl;        


        
         

    }
    return 0;
}
