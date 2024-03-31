#include <bits/stdc++.h>
#include <sys/types.h>
#include <vector>
#define ll long long
const int N = 3*1e5;
using namespace std;

long r[N], l[N], a[N];


int main (int argc, char *argv[]){
    int t;
    cin >> t;    

    while (t--) {
        int n, m, x, y;
        long aux, dist; 
        
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        
    
        r[0] = 0;
        l[n-1] = 0;
        dist = 1e9+1;
        for(int i = 1; i < n; i++){
            aux = abs(a[i-1] - a[i]);
            r[i] = (aux > dist)? aux : 1;
            r[i] += r[i-1];
            dist = aux;
        }
        
        dist = 1e9+1;
        for(int i = n-2; i >= 0; i--){
            aux = abs(a[i+1] - a[i]);
            l[i] = (aux > dist)? aux : 1;
            l[i] += l[i+1];
            dist = aux;
        }
        

        long asw;
        cin >> m;
        while (m--) {
            
            cin >> x >> y;
            if(y > x) { 
                asw = r[y-1] - r[x-1];

            }
            else{
                asw =  l[y-1] - l[x-1];
            }
            cout << asw << endl;
        }


    

    }


    return 0;
}
