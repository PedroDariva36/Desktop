#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <vector>
#define ll long long
#define pii pair<int,int>



using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        
        int n;
        cin >> n;

        vector<pii> g[2];
        vector<pii> father[2];
        vector<int> a[2];
        
        for (int i = 0; i < n; i++) {
            g[0].push_back({10e5-1,0});
            g[1].push_back({10e5-1,0});
            
            father[0].push_back({-1,-1});
            father[1].push_back({-1,-1});
        }
        cout << n << endl; 
        char aux;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            a[0].push_back(aux - '0');
        }    
        for (int i = 0; i < n; i++) {
            cin >> aux;
            a[1].push_back(aux - '0');
        }    
        
        queue<pii> q;
        q.push({1,n-1});
        g[1][n-1] = {a[1][n-1], 1};
        while (!q.empty()) {
            auto c = q.front(); q.pop();
            if(c.first == 0 && c.second == 0) continue;
            cout << c.first << " " << c.second << endl; 
            pii cv = g[c.first][c.first];
            int hv = 10e5;
            pii h = {-1,-1}; 
             pii v = {c.first,(c.second ? 0 : 1)};
            int vv = a[c.first][(c.second ? 0 : 1)];

            if (c.first > 0) {
                hv = a[c.first-1][c.second];
                h = {c.first-1,c.second};
            }
            
                       if (vv == hv) {
                int ha = a[h.first][h.second];
                if(g[h.first][h.second].first > cv.first + ha) {
                    g[h.first][h.second] = cv;
                    g[h.first][h.second].first += ha;
                    q.push(h);
                }
                if(g[h.first][h.second].first == cv.first + ha)
                    g[h.first][h.second].second += cv.second; 
                father[h.first][h.second] = {c.first,c.second};
                

                int va = a[v.first][v.second];
                if(g[v.first][v.second].first > cv.first + va) {
                    g[v.first][v.second] = cv;
                    g[v.first][v.second].first += va;
                    q.push(v);
                }
                if(g[v.first][v.second].first == cv.first + va)
                    g[v.first][v.second].second += cv.second; 
                father[v.first][v.second] = {c.first,c.second};
                
            }
            if (vv > hv) {
                int va = a[v.first][v.second];
                if(g[v.first][v.second].first > cv.first + va) {
                    g[v.first][v.second] = cv;
                    g[v.first][v.second].first += va;
                    q.push(v);
                }
                if(g[v.first][v.second].first == cv.first + va)
                    g[v.first][v.second].second += cv.second; 
                father[v.first][v.second] = {c.first,c.second};
            }
            if (vv < hv) {
                int ha = a[h.first][h.second];
                if(g[h.first][h.second].first > cv.first + ha) {
                    g[h.first][h.second] = cv;
                    g[h.first][h.second].first += ha;
                    q.push(h);
                }
                if(g[h.first][h.second].first == cv.first + ha)
                    g[h.first][h.second].second += cv.second; 
                father[h.first][h.second] = {c.first,c.second};
            }
        }
    }

    return 0;
}
