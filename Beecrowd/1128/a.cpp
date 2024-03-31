#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;



int n, m, a, b, c;
int main (int argc, char *argv[]){
    while(cin >> n >> m){ 
        if (n == 0 || m == 0) break;
        vector<int> g[n], t[n];
        queue<int> q;

        bool marked[n];
        for (int i = 0; i < n; i++) marked[i] = 0;

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;        
            g[a-1].push_back(b-1);
            t[b-1].push_back(a-1);
            if (c == 2){ 
                g[b-1].push_back(a-1);
                t[a-1].push_back(b-1);
            }
        }

        q.push(0);
        while (!q.empty()) {
            for (auto i : g[q.front()]) {
                if (marked[i]) continue;
                marked[i] = true;
                q.push(i);
            }
            q.pop();
        }

        bool flag = false;
        for (int i = 0; i < n; i++){
            if (!marked[i]) {
                flag = true;
                break;
            }
            marked[i] = false;
        }
        
        if (flag) {
            cout << "0" << endl;
            continue;
        }

        q.push(0);
        while (!q.empty()) {
            for (auto i : t[q.front()]) {
                if (marked[i]) continue;
                marked[i] = true;
                q.push(i);
            }
            q.pop();
        }

        for (int i = 0; i < n; i++){
            if (!marked[i]) {
                flag = true;
                break;
            }
        }
        
        if (flag) {
            cout << "0" << endl;
            continue;
        }
        
        cout << "1" << endl;
    }
    return 0;
}
