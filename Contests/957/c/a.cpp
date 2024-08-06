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
        int n, m , k;
        cin >> n >> m >> k;
    
        vector<int> a;

        for (int i = n;  i >= 1;  i--) {
            if(i > m) a.pb(i);
        }
        
        for (int i = 1;  i <= n;  i++) {
            if(i <= m) a.pb(i);
        } 

        for (auto i: a) {
            cout << i << " ";
        }
        cout << endl;

         

    }
    return 0;
}
