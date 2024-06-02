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
        int n;
        cin >> n;
        
        vector<long> b(n);
        vector<long> a(n);
    
        for (auto &i : a) {
            cin >> i;
        }
        for (auto &i : b) {
            cin >> i; 
        }
        
        ll sum = 0;
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (a[k] > b[i] ) {
                sum++; 
            }
            else {
                k++;
            }
        }

        cout << sum << endl;


    }

    return 0;
}
