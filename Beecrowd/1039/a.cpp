#include <bits/stdc++.h>
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
    int r1, r2, x1,x2,y1,y2; 

    while (cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2) {
        if(edist(x1,x2,y1,y2) + r2 > r1) 
            cout << "MORTO";
        else 
            cout << "RICO";
        cout << endl;
    }

    return 0;
}
