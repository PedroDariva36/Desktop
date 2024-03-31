#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <vector>
#define ll long long
#define MAX 10e5+1

using namespace std;

int best[1000001];
int n;
int t, m, aux;
int main (int argc, char *argv[]){
    
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i <= m; i++) best[i] = MAX;
        vector<int> values;
        
        for (int i = 0; i < n; i++) {
            cin >> aux;
            values.push_back(aux);
        }

        best[0] = 0;
        for (int x = 1; x <= m; x++) {
            best[x] = MAX;
            for (auto i : values) {
                if (x-i >= 0) {
                    best[x] = min(best[x], best[x-i]+1);
                }
            }
        }
        cout << best[m]<<endl;
    }
    return 0;
}
