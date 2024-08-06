#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int x, y, a, b, v, r, rc;
    while (cin >> x >> y >> a >> b >> v >> r >> rc) {
        
        double dist = sqrt((x-a)*(x-a) + (y-b)*(y-b));
        dist += 1.5*v;
        
        if(dist > rc + r) cout << "N";
        else cout << "Y";
        cout << endl;

    }

    return 0;
}
