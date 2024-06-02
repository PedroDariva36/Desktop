#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        long n, c ,d,aux;
        cin >> n >> c >> d;

    
        multiset<long> a,b;

        for (int i = 0; i < n*n; i++) {
            cin >> aux;
            a.insert(aux);
        }
        aux = *(a.begin());
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b.insert(aux + i*d + j*c); 
            }
        }
     

        cout << ((a==b)? "YES" : "NO") << endl;
                

    }

    return 0;
}
