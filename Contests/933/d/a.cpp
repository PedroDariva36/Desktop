#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        char c;
        int n, m, x, aux;
        cin >> n >> m >> x;
            
        vector<pair<int, int>> a;
        set<int> g[m+1];
        
        for (int i = 0; i < m; i++) {
            cin >> aux;
            cin >> c;
            
            if (c == '0') 
                a.push_back({aux,0});
            if (c == '1')
                 a.push_back({aux,1});
            if (c == '?') 
                a.push_back({aux,2});
        }
        g[0].insert(x);
        for (int i = 0; i < m; i++) {
            for (auto j : g[i]) {
                if(a[i].second == 0)
                    g[i+1].insert(abs(j+a[i].first)%n);

                if(a[i].second == 1){
                    if (j-a[i].first < 0)
                        g[i+1].insert(((n+j)-a[i].first)%n); 
                    else   
                        g[i+1].insert((j-a[i].first)%n);
                }
                if(a[i].second == 2){
                    g[i+1].insert(abs(j+a[i].first)%n);
                    if (j-a[i].first < 0)
                        g[i+1].insert(((n+j)-a[i].first)%n); 
                    else   
                        g[i+1].insert((j-a[i].first)%n); 

                }
            }
        }
        cout << g[m].size() << endl;
        for (auto &i : g[m]) {
            if (i != 0)
                cout << i << " ";
        }
        if (g[m].count(0) > 0)
            cout << n;
        cout << endl;

    }

    return 0;
}
