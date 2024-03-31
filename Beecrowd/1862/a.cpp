#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int g[1001][1001];
bitset<1000> marked;
vector<int> asw;

int main (int argc, char *argv[]){
    
    int n, t;
    cin >> n; 
    char aux;

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            cin >> aux;        
            if (i == j){ 
                g[i][j] = 0;
                continue;
            }
            g[i][j] = (aux == 'S') ? 1:0;
        }
    }

    int first;
    int lastValue = 0;
    int sum = 0;

    while (true){
        
        first = -1;
        for (int i = 0; i < n; i++){
            if (!marked[i]) {
                first = i;
                break;
            }
        }
        if (first == -1) break;
        
        int c = 0;
        stack<int> s;
        s.push(first);
        while (!s.empty()) {
            t = s.top(); s.pop();
            if (marked[t]) continue; 
            marked[t] = true;
            for (int u = 0; u < n; u++) {
                if (g[t][u] == 1){
                    s.push(u);
                    c++;
                }
            }
        }
        sum = 0;
        for (int i = 0; i < n; i++) if (marked[i] == 1) sum++;
        
        int x = sum - lastValue; 
        if (x*(x-1) != c) {
            cout << -1 << endl;
            return 0;
        }

        if(x != 0) asw.push_back(abs(sum - lastValue));
        lastValue = sum;
    }

    sort(asw.rbegin(),asw.rend()); 
    cout << asw.size() << endl;
    cout << asw[0];
    for (int i = 1; i < asw.size(); i++) cout << " " << asw[i];
    cout << endl;

    return 0;
}
