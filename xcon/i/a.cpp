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
    
    ull p;
    cin >> p;
    

    bool f = 0;
    
    if(p%2 != 0){
        if((p-1)%4) f = 1;
        if((p-3)%4) f = 1;

    }
        
    cout << (f?"S":"N") << endl;
 

    return 0;
}
