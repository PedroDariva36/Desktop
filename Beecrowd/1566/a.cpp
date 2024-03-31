#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>

using namespace std;


int a[250];
int t,x;
long n;

int main (int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        while (n--) {
            cin >> x;
            a[x]++;
        }        
        
        int i = 0;
        while (i < 250) {
            if (a[i] > 0) break;
            i++;
        }
        cout << i;
        a[i]--;
        for (; i < 250; i++) {
            while(a[i] > 0){
                cout <<" "<<  i;
                a[i]--;
            }
        }
        
        cout << endl;
    }

    

    return 0;
}
