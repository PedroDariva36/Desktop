#include <bits/stdc++.h>
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
        int n,m,k;
        cin >> n >> m >> k;
        

        if (m == 1) {
            cout << "NO" << endl;
            continue;
        }

        map<int,int> a;

        for (int i = 0; i < n; i++) {
            a[i%m]++;
        }
        
        int v = 0;

        for (auto i : a) {
            v = max(v,i.second); 
        }
        if ((n-v) > k) {
            cout << "YES" << endl; 
        }
        else {
            cout << "NO" << endl;
        }



        
    }

    return 0;
}
