#include <bits/stdc++.h>
#define ll long long


using namespace std;


int t;
int main (int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--){
    int n,m;
    ll asw;
    cin >> n >> m;
    
    asw = m/ 2;
    ll k = m % 2;
    
    asw *= n;
    if(m == 1) asw--;

    cout << asw << endl;



    }
    return 0;
}
