#include <bits/stdc++.h>
#include <climits>
#include <vector>

#define pii pair<int,int>
#define f first
#define s second


using namespace std;

int main (int argc, char *argv[]){
    
    int t, n, k, aux;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        
        vector<pii> a;
        vector<int> memo;

        for (int i = 0; i < n; i++) {
            cin >> aux;
            a.push_back({aux,0});
            memo.push_back(0);
        }
        
        for (int i = 0; i < n; i++) cin >> a[i].second;

        int local = 0;
        for (int i = n-1; i >= 0; i--){
            int mx = 0;
            for (int j = i+1; j < n; j++) {
                if (a[j].f - a[i].f >= k)
                    mx = max(mx, memo[j]);
            }
            memo[i] = a[i].second + mx;
            local = max(local, memo[i]);
        }
        cout << local << endl; 

    }



    return 0;
}
