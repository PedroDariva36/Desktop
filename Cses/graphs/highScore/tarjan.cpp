#include <bits/stdc++.h>
#include <vector>
#define N 1000000
using namespace std;



vector<pair<int, long>> g[N];
int num[N];
int low[N];
bool marked[N];
stack<int> s;
int t = 0;


void tarjanSearch(int x){
    num[x] = t;
    low[x] = t;
    t++;

    s.push(x);
    marked[x] = true;

    for (auto i : g[x]) {
        if (num[i.first] == -1){
            tarjanSearch(i.first);
            low[x] = min(low[x],low[i.first]);
        }
        else if(marked[i.first]) low[x] = min(low[x], num[i.first]);
    }
    if (low[x] == num[x]) {
        int y;
        vector<int> l;
        while (s.top() != x) {
            y = s.top();
            cout << y+1 << " ";
            marked[y] = false;
            s.pop();
        }
        y = s.top();
        cout << y+1 << endl;
        marked[y] = false;
        s.pop();

    }
}



int main (int argc, char *argv[]){


    int n,m,a,b;
    long c;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        num[i] = -1;
        low[i] = -1;
        marked[i] = false;
    }

    while(m--){
        cin >> a >> b >> c;
        g[a-1].push_back({b-1, c});
    }



    for (int i = 0; i < n; i++)
        if (num[i] == -1)
            tarjanSearch(i);



    return 0;
}
