#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;

int main (int argc, char *argv[]){
    int t;
    cin >> t;
        
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        long aux;
        vector<long> a, b;

        for (int i = 0; i < n; i++) {
            cin >> aux;
            a.push_back(aux);
        }
        
        for (int i = 0; i < m; i++) {
            cin >> aux;
            b.push_back(aux);
        }
            
        sort(a.begin(), a.end());
        sort(b.rbegin(),b.rend());

        int fa = 0, fb = 0;
        int la = n-1, lb = m-1;
        
        ll sum = 0;
        cout << "------" << endl;
        bool g = 0;
        while (fa < la) {
            if (g) {
                sum += abs(a[fa] - b[fb]);
                fa++;
                fb++;
            }

            else {
                sum += abs(a[la] - b[lb]);
                la--;
                lb--;
            }
            g = !g;
        }
        cout << sum << endl; 
    }



    return 0;
}
