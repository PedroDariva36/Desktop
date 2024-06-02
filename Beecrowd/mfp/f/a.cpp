#include <bits/stdc++.h>

using namespace std;


int main (int argc, char *argv[]){
    int n; 
    int a, b;
    string t, s, c;
    cin >> n;
    int p[3]; 
    p[1] = 0;
    p[2] = 0;
    for (int i = 0; i < n; i++) {
        cin >> t; 
        cin >> a;
        cin >> c;

        b = c[1] - '0';
         

        p[a] += b;
    }
    cout << p[1] << " x " << p[2] << endl;


    return 0;
}
