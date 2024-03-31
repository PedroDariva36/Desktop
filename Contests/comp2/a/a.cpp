#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define ll long long
#define pii pair<int,int>
#define pis pair<int,set<int>>
#define f first
#define s second

int marked[1001];


using namespace std;

int main (int argc, char *argv[]){
    int n, m, k, aux, l;
    cin >> n >> m;
    
    vector<pii> g[n+1];
    
    for (int i = 1; i < n+1; i++) marked[i] = m;

    for (int i = 0; i < m; i++) {
        cin >> k >> aux;
        for (int j = 1; j < k; j++) {
            cin >> l;
            g[aux].push_back({l,i});
            g[l].push_back({l,i});
            aux = l;
        }
    }
/*
    for (int i = 0; i <= n; i++) {
        for (auto j : g[i]) {
            cout << "(" << j.first << "|" << j.second << ") ";
        }
    }
*/
    queue<pis> q;
    for (auto i : g[1]) {
        set<int> x;
        x.insert(i.second);
        q.push({i.first,x});
    }

    while (!q.empty()) {
        pis c = q.front(); q.pop();

        for (auto u : g[c.first]) {
            set<int> s = c.second;
            s.insert(u.s);
            if (marked[u.f] <= s.size()) continue;
            marked[u.f] = s.size();
            q.push({u.f, s});
        }
    }

    cout << marked[n] << endl;



    return 0;
}
