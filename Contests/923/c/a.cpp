#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;


int main (int argc, char *argv[]){
    int t;
    cin >> t;
    while (t--) {
        int n,m,k;
        cin >> n >> m >> k;
        int aux;
        set<int> a, b;

        for (int i = 0; i < n; i++) {
            cin >> aux;
            a.insert(aux);
        }
        for (int i = 0; i < m; i++) {
            cin >> aux;
            b.insert(aux);        
        }
        
        int ac = 0, bc = 0;
        bool ax,bx;
        
        bool flag = true;
        for (int i = 1; i <= k; i++) {
            ax = a.count(i);
            bx = b.count(i);
            if (ax & bx) continue;
            if(!ax && !bx){
                flag = false;
                break;
            }

            if (ax) ac++;
            if (bx) bc ++;
        }
        
        if(flag){
            aux = max(ac,bc);
            if(aux > k/2){
                cout << "NO" << endl;
            }
            else cout << "YES" << endl;
                
        }
        
        else cout << "NO" << endl;


    }
    return 0;
}
