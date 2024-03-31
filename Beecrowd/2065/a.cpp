#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <utility>
#include <vector>


using namespace std;

int n, m, aux;
long long mt = 0;
priority_queue<pair<int , int>> q;
priority_queue<int> f;
queue<int> c;

int main (int argc, char *argv[]){
    
    cin >> n >> m;
    
    for (int i = 0 ; i < n; i++) {
        cin >> aux;
        f.push(-aux);
    }

    for (int i = 0 ; i < m; i++){
        cin >> aux;
        c.push(aux);
    }


    int i = 0;
    while (!c.empty()) {
        if(!f.empty()){
            q.push({f.top() * c.front() + i, f.top()});
            c.pop();
            f.pop();
            continue;
        }
        

        if(q.top().first == i) {
            f.push(q.top().second);    
            q.pop();
            continue;
        }
    
        f.push(q.top().second);
        i = q.top().first;
        q.pop();
    }
    

    if (!q.empty()) {
        aux = q.top().first;
        cout << -aux << endl;
        q.pop();
    }
    
    cout << -aux << endl;
    return 0;
}
