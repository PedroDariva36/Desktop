#include <bits/stdc++.h>
#include <ios>
#include <unistd.h>
#include <vector>
#define N 2501
#define ll long long
#define pil pair<int,long>
#define INF 1e10
 
using namespace std;

vector<pil> g[N];
vector<ll> d;
int father[N];
bool marked[N];
int n,m,a,b;
long c;
 



int main (int argc, char *argv[]){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
 
    cin >> n >> m;
 
    while (m--) {
        cin >> a >> b >> c;
        g[a-1].push_back({b-1,c});
    }     
    
    for (int i = 0; i < n; i++ ) {
        father[i] = -1;
        d.push_back(INF);
        marked[i] = false;
    }
    
    int flag;

    d[0] = 0;
    for (int z = 0; z < n; z++) {
        flag = -1;
        for (int i = 0; i < n; i++ ) {
            for (auto &j : g[i]) {
                if (d[j.first] > d[i]+ j.second){
                    d[j.first] = d[i]+ j.second;
                    father[j.first] = i;
                    flag = j.first;
                }
            }
        }
    }
    

    if(flag == -1) {
        cout << "NO" << endl; 
        return 0;
    }
    vector<int> cy;
    for (int z = 0; z < n-1; z++) {
        flag = father[flag];
    }
    
    for (int x = flag ; ; x = father[x]) {
        cy.push_back(x);

        if (x == flag && cy.size() > 1) break;
    }
     
    cout << "YES" << endl;
    for (int i = cy.size()-1; i >= 0; i--) cout << cy[i]+1 << " ";
    cout << endl;
    
    //for (int i = 0; i < n; i++) cout << i << " : " << father[i] << endl;
    
 
 
    return 0;
}
