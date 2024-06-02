#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

const int N = 2*1e4;
int father[N] = {-1};
int rk[N] = {0};

void make_set(int v) {
    father[v] = v;
    rk[v] = 0;
}

int find_set(int v) {
    if (v == father[v])
        return v;
    return father[v] = find_set(father[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (rk[a] < rk[b]) swap(a,b);
        father[b] = a;
        if (rk[a] == rk[b]) rk[b]++;
    }
}

double eulerDist(int x0, int x1, int y0, int y1){
    return sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    int a, b, c;
    cin >> m >> n >> k;
    
    int g[k+5][3];
    
    for (int i = 0; i < 4; i++) 
        make_set(i); 

    for (int l = 4; l < k+4; l++) {
        cin >> a >> b >> c;
        make_set(l);
        g[l][0]=a;
        g[l][1]=b;
        g[l][2]=c;
        if (a - c <= 0) union_sets(l, 0);
        if (a + c >= m) union_sets(l, 1);
        if (b - c <= 0) union_sets(l, 2);
        if (b + c >= n) union_sets(l, 3);
    }

    for (int i = 4; i < k + 4; i++) {
        for (int j = i+1; j < k+4; j++) {
            if ((double)(g[i][2] + g[j][2]) >= eulerDist(g[i][0], g[j][0], g[i][1], g[j][1])) {
                if (find_set(i) != find_set(j)) {
                    union_sets(i,j); 
                }
            } 
        }
    }


    if(find_set(3) == find_set(1) || find_set(3) == find_set(2) || find_set(0) == find_set(1) || find_set(0) == find_set(2))
        cout << "N" << endl;
    else
        cout << "S" << endl;


    return 0;
}
