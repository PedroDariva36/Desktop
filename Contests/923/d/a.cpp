#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;


int main (int argc, char *argv[]){
    int t;
    cin >> t;
    while (t--) {
        int n,aux;
        cin >> n;

        vector<int> a;
        vector<int> prefix;
        a.push_back(0);
        prefix.push_back(0);
        for (int i = 0; i < n; i++) {
             cin >> aux;
             a.push_back(aux);
        }
        for (int i = 1; i <= n; i++) {
            if(a[i] != a[i-1]){
                prefix.push_back(prefix[i-1] +1);
            }
            else {
                prefix.push_back(prefix[i-1]);  
            }
        }
        
        int m;
        int k;
        int x,y;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            
            if (prefix[y] - prefix[x] > 0) {
                while (a[y] == a[x] && x < y) {
                    
                    k = (y + x) >> 1;
                    if (abs(prefix[k] - prefix[y]) > 0)
                        x = k;
                    else 
                        y = k;            
                }

                cout << x << " " << y << endl;
            }
            else {
                cout << -1 << " " << -1 << endl;
            }
        }


    }
    return 0;
}
