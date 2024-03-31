#include<bits/stdc++.h>
#define ll long long 
#define pill pair<int,ll>

using namespace std;



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p, g, a, b;
    ll c;

    cin >> n >> m;
    cin >> p >> g;
    vector<pill> gr[n];
    vector<int> path;
    ll dist[n];
    ll dist2[n];
    bool gson[n];
    int marked[n];
    int father[n]; 
    p--;
    g--;
    
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;    
        gr[a-1].push_back({b-1,c});
        gr[b-1].push_back({a-1,c});
    }
    

    for (int i = 0; i < n; i++){
        gson[i] = 0;
        marked[i] = false;
        dist[i] = LLONG_MAX;
        dist2[i] = LLONG_MAX;
        father[i] = -1;
    }
    
    priority_queue<pair<ll,pair<int, bool>>> q;
    q.push({0,{p,0}});
    dist[p] = 0;
    while (!q.empty()){
        bool status = q.top().second.second;
        int c = q.top().second.first; q.pop();
        if (marked[c])continue;
        marked[c] = true;

        if(c == g) status = 1;

        for (auto i : gr[c]){
            int b = i.first;
            ll w = i.second;


            if(dist[c]+ w < dist[b]){
                gson[b] = c;
                dist[b] =  dist[c]+ w;
                gson[b] = status;
                q.push({-dist[b],{b,status}});
            }
        }
    }

    for(int i = 0; i < n; i++){
        marked[i] = 0;
    }
    marked[g] = true;
    priority_queue<pair<ll,int>> qs;
    qs.push({0,p});
    dist2[p] = 0;
    while (!qs.empty()){
        int c = qs.top().second; qs.pop();
        if (marked[c])continue;
        marked[c] = true;

        for (auto i : gr[c]){
            int b = i.first;
            ll w = i.second;


            if(dist2[c]+ w < dist2[b]){
                dist2[b] =  dist2[c]+ w;
                qs.push({-dist2[b],b});
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(dist[i] == dist2[i]) gson[i] = 0;
    }

    ll dg = dist[g]; 
    for (int i = 0; i < n; i++){
        if(dist[i] == 2*dg && gson[i])
            path.push_back(i+1);
    }
    
    if(path.empty()) cout << "*" << endl;
    
    else{
        for(auto i: path)
            cout << i << " ";
        cout << endl;
    }

    /*
    for(auto i: dist2){
        cout << i << " ";
    }
    cout << endl;

    for(auto i: dist){
        cout << i << " ";
    }
    cout << endl;
    */

    return 0;
}
