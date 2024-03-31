#include <bits/stdc++.h>
#include <vector>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n,m,k;
        cin >> n >> m >> k;
        vector<int> a(n), b(m);       
        for (auto &i : a) {
            cin >> i;
        }
        for (auto &i : b) {
            cin >> i;
        }
        ll sum = 0; 
        for (auto &i : a) {
            for (auto &j : b) {
                if (i + j <= k) {
                    sum++; 
                } 
            } 
        }
        cout << sum << endl; 




    }

    return 0;
}
