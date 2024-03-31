#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        int f1 = -1;
        vector<int> a(n);
        for (int i = n-1 ; i >= 0; i--) {
            cin >> a[i];
            if(a[i] == 1) f1 = i;
        }
        if (f1 == -1) {
            cout << 0 << endl;
            continue;
        }
        ll sum = 0;
        for (int i = n-1; i > f1; i--) {
            if (a[i] == 0) continue;
            
            int x = -1;
            for (int j = i-1; j > f1; j--)
                if(a[j] == 0){
                    x = j;
                    break;
                }
        
            if (x == -1) break;
            swap(a[x],a[i]);
            sum++;
        }
        
        cout << sum << endl;




    }

    return 0;
}
