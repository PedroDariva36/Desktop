#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int dt(int x, int y){
    return y*y + x*x;
}

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        long r;
        cin >> r;
        ll asw = 0;
        
        int x = 0;
        int y = r;
        
        while(y > 0){
            int d = dt(x,y);
            int dp1 = dt(x+1,y); 
            if (d >= r*r && d < (r+1)*(r+1)) asw++; 
            
            (dp1 >= (r+1)*(r+1) ? y-- : x++);
        }


        cout << asw * 4 << endl;
    }

    return 0;
}
