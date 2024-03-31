#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
#define N 2000001

using namespace std;
int n, m, aux, x ,y;
vector<pair<int, int>> ac;
int a[N];
int t[N];





int main (int argc, char *argv[]){
    
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    

    for(int i = 1; i <= n; i++){
        cin >> aux;
        a[aux] = i;
        t[i] = aux;
    }

    for(int i = 0; i < m; i++){
        cin >> x >> y;
        ac.push_back({x,y});
    }

    x = 0; y = 0;
    for (auto k : ac) {
        
        swap(a[t[k.first]],a[t[k.second]]);
        swap(t[k.first],t[k.second]);


        int sum = 0;
        int last = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < last) sum++;
            last = a[i];
        }
        cout << sum+1 << endl;

    }
    return 0;
}
