#include <bits/stdc++.h>
#include <vector>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> a;
        for (int i = k; i > 0; i--) {
            if (i == x) continue; 
            while(n%i == 0 && n != 0) {
                n = n-i;
                a.push_back(i);
            }
            if (n == 0) break; 
        }

        if (n != 0) {
            cout << "NO" << endl; 
            continue;
        }
        

        cout << "YES" << endl;
        cout << a.size() << endl;
        for (auto &i : a) {
            cout << i << " "; 
        }
        cout << endl;

    }

    return 0;
}
