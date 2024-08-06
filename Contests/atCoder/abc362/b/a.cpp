#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <unistd.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);

    vector<pair<int,int>> a;
    vector<double> dist;

    int x, y;
    for(int i = 0; i < 3; i++){
        cin >> x >> y;
        a.push_back({x,y}); 
    }
    for (int i = 0; i < a.size()-1; i++) {
        for (int j = i+1; j < a.size(); j++) {
            dist.pb(hypot(a[i].first - a[j].first,a[i].second - a[j].second));
            //cout << dist.back() << endl;;
        } 
    }

    sort(all(dist));
    if(dist[2] == hypot(dist[1],dist[0])){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;




    return 0;
}
