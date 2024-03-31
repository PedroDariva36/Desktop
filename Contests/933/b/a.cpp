#include <bits/stdc++.h>
#include <vector>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<long> a(n);
        for (auto &i : a) {
            cin >> i; 
        }
        
        bool flag = true;
        for (int i = 0; i < n-2; i++) {
            if (a[i] == 0) continue;
            if (a[i+1] < 2*a[i] || a[i+2] < a[i]) {
                flag = false; 
                break;
            }
            a[i+2] -= a[i];
            a[i+1]-=2*a[i];
            a[i]-= a[i];
            
        }
       if (a[n-1] > 0 || a[n-2] > 0) flag = false;

       cout << (flag? "YES" : "NO") << endl;

    }

    return 0;
}
