#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

const int N = 200002;
int father[N];
int sz[N];


int find_set(int v) {
    if (v == father[v])
        return v;
    return find_set(father[v]);
}

void make_set(int v) {
    father[v] = v;
    sz[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        father[b] = a;
        sz[a] += sz[b];
    }
}





int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    while(cin >> n >> m){
        if(n == m && n == 0) break;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;
        for (int i = 0; i < n; i++) make_set(i);


        ll sum = 0;
        int a, b, c;
        for(int i = 0; i < m; i++){
            cin >> a >> b >> c;
            sum += c; 
            q.push({c,a,b});
        }
        ll ksum = 0; 
        while (!q.empty()) {
            tie(c,a,b) = q.top(); q.pop();                  
            if (find_set(a) != find_set(b)) {
                ksum += c;
                union_sets(a, b);
            }
        }

        cout << abs(ksum - sum) << endl;    
    }

         
        
    return 0;
}
