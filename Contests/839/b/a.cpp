#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

bool solve(int a, int b, int c, int d){
    return (a < b && a < c && b < d && c < d);
}

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int a,b,c,d; 
        cin >> a >> b >> c >> d;        

        bool f = 0;
        for (int i = 0; i <  4; i++){ 
            if(solve(a,b,c,d)) f = 1; 
            swap(a,b);
            swap(a,d);
            swap(a,c); 
         }
        cout << (f? "YES": "NO") << endl;

        
         

    }
    return 0;
}
