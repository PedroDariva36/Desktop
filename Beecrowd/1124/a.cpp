#include <bits/stdc++.h>
#include <iterator>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;


float edist (int x1, int x2, int y1, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int x, y, r1, r2;

   while (cin >> x >> y >> r1 >> r2 && x != 0) {
        
        if (2*r1 > x | 2*r1 > y | 2*r2 > x | 2*r2 > y) {
            cout << "N" << endl;
            continue;
        }
        
        if(edist(0 + r1, x - r2, 0 + r1, y - r2) < (r1+r2))
            cout << "N";
        else
            cout << "S";
        cout << endl;
    }

    return 0;
}
 
