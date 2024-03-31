#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
#define ll long long

using namespace std;



int main (int argc, char *argv[]){
    
    cin.tie(0)->sync_with_stdio(0);


    int t = 0, n,aux,x,y;
    cin >> t;
    
    while (t--) {
        cin >> n;
        vector<pair<int,int>> a;
        while (n--) {
            cin >> x >> y;
            a.push_back({x,y});
        }
        sort(a.begin(),a.end());
        int limit = INT_MAX;
        for (auto i : a) {
            if(i.first > limit) break;
            aux = i.first + i.second/2;
            if (i.second % 2 == 0) aux--;
            limit = min(limit, aux);
        }
        cout <<limit << endl;
    }


    return 0;
}
