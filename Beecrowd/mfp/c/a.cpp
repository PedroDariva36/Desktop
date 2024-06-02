#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>

using namespace std;


int main (int argc, char *argv[]){
    int x, y; 
    vector<pair<int, int>>a;
    for (int i = 0; i < 4; i++) {
        cin >> x >> y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end());

    int k = max(abs(a[0].first - a[1].first),abs(a[0].second - a[1].second));
    cout << k*k << endl;

    return 0;
}
