#include <bits/stdc++.h>
#include <math.h>
#include <queue>
#include <vector>
#define ll long long
using namespace std;

int main (int argc, char *argv[]){

    int n,m,aux;
    vector<int>  a;
    queue<int> b;
    ll act = 0;
    ll total = 0;
     
    cin >> act >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> aux;
        a.push_back(aux);
    }


    total += m;
    while (m--) {
        cin >> aux;
        act += aux;
    }
    

    cout << act << endl;
    while ) {
    
    } {
        if (act >= a[i]){
            act -= a[i];
            total++;
        }

        cout << act << endl;

    }     
    cout << total << endl;

    

    return 0;
}
