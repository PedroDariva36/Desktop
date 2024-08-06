#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
        int r, g, b;
        string c;
        cin >> r >> g >> b;
        cin >> c; 
        
        if(c == "Red"){
            cout << min(b,g) << endl;
        }    
        if(c == "Blue"){
            cout << min(r,g) << endl;
        }
        if(c == "Green"){
            cout << min(b,r) << endl;
        }

    return 0;
}
