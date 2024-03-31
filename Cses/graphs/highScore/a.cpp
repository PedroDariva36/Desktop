#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <unistd.h>
#include <vector>
#define N 2501
using namespace std;



vector<pair<int, long>> g[N];
vector<vector<int>> scc;
vector<long long>d;
int inCycle[N];

int num[N];
int low[N];
bool marked[N];
stack<int> s;
int t = 0;


int dfs(int x,int n){
    if (x == n-1) return 1;
    if (marked[x] == true) return 0; 
    marked[x] = true;

    int res = 0;
    for (auto i : g[x]) 
        res = max(dfs(i.first,n), res);
    return res;
}

int main (int argc, char *argv[]){
    

    int n,m,a,b;
    long c;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        marked[i] = false;
        d.push_back(LLONG_MAX);
    }   
    
    while(m--){
        cin >> a >> b >> c;
        g[a-1].push_back({b-1, -c});
    }

    
    dfs(0,n);
    d[0] = 0;
    for (int z = 0; z < n-1; z++)
        for (int i = 0; i < n; i++){
            for (auto j: g[i]) 
                if(d[i] != LLONG_MAX && d[j.first] > d[i] + j.second){
                    d[j.first] = d[i] + j.second;
                }
        }

    for (int i = 0; i < n; i++)
        for (auto j: g[i])
            if(d[i] != LLONG_MAX && d[j.first] > d[i] + j.second){
                for (auto &i : marked) i = false;

                if (dfs(i,n)) {
                    cout << -1 << endl;
                    return 0;
                }
            }

    //for (auto i : d) cout << i << endl;

    cout << -d[n-1] << endl;
        


    return 0;
}
