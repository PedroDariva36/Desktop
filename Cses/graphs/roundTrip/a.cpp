#include <bits/stdc++.h>
#include <stack>
#define N 1000001
using namespace std;

vector<int> g[N];
int father[N];
bool marked[N];

int cycleRoot = -1;
int cycleLast = -1;


bool dfs(int start) {
    stack<int> s;
    
    s.push(start);
    
    while (!s.empty()) {
        int c = s.top(); s.pop();
        if(marked[c]) continue;
        marked[c] = true;
        for (auto i: g[c]) {
            if (marked[i]) {
                if (i != father[c]) {
                    cycleRoot = c;
                    father[i] = c;
                    return true;
                }
                else continue;
            }

            father[i] = c;
            s.push(i);
        }
    }
    return false;
}

int main (int argc, char *argv[]){
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        father[i] = -1;
        marked[i] = false;
    }


    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    

    for (int i = 0; i <= n; i++) {
        if (dfs(i)) break;
    }

    if (cycleRoot == -1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    /*
    for (int i = 1; i <= n; i++) 
        cout << i << " ";
    cout << '\n';
    for (int i = 1; i <= n; i++) 
        cout << father[i] << " ";
    cout << '\n';
    */

    vector<int> steps;
    steps.push_back(cycleRoot);
    int aux = father[cycleRoot];
    
    while (aux != cycleRoot) {
        steps.push_back(aux);
        aux = father[aux];
    }
    steps.push_back(aux);
    cout << steps.size()<< endl;
    for (auto i : steps) 
        cout << i << " ";
    cout << endl;
    return 0;
}
