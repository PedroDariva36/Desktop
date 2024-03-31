#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define pii pair<int,int>

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        char aux;;
        cin >> n;
        
        vector<int>a;
        a.push_back(-1);
        for (int i = 0; i < n; i++) {
            cin >> aux;
            a.push_back(aux-'0');
        }

        vector<int> l(n+2), r(n+2);
        int k = 0;
        for (int i = 1; i < n+1; i++) {
            if(a[i] == 1) k++; 
            r[i] = k;
        }
        k = 0;
        for (int i = 1; i < n+1; i++) {
            if(a[i] == 0) k++; 
            l[i] = k;
        }
        l[0] = 0;
        r[0] = 0;
        
        int m = n;
        int pos;
        int x; 
        int mid = n/2;
        if (n%2 == 1) {
            mid++;
        }

        for (int i = 0; i <= mid; i++) { 
            cout << i << " ";
            if (m > abs(n/2 - i)) {
                k = i/2;
                if (i%2 == 1) k++;
                x = (n-i)/2;
                if (n-i%2 == 1) x++;
                
                if (l[i] >= k && (r[n]-r[i]) >= x) {
                    m = abs(n/2 - i);
                    pos = i;
                }
            }
        }
        
        cout << pos << endl;








    }

    return 0;
}
