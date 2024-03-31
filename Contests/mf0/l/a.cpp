#include<bits/stdc++.h>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define ppi pair<pii,int>
#define f first
#define s second
using namespace std;

int g[1002][1002];

int n,m,a,b,c,x,y,r,t; 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<ppi> s;
    cin >> n >> m;
    cin >> t;

    while (t--) {
        cin >> a >> b >> c;
        s.push_back({{a,b},c});
    }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            g[i][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (auto &k : s) {
                if ( i > k.f.f + k.s || i < k.f.f - k.s) continue;
                if ( j > k.f.s + k.s || j < k.f.s - k.s) continue;
                g[i][j]++;
            }
        }
    }
    long sum = 0; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum += g[i][j] ;
        }
    }
    cout << sum/(n*m) << endl;

    

    
    return 0;
}
