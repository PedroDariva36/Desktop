#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

bool see(int a[], int c[], int n){
    for (int i = 0; i < n/2; i++)
        if (a[i] != c[i])
            return true;
    return false;
}

int n, counter = -1;
int main (){

    cin >> n;
    int a[n], b[n], c[n];

    for (int i = 1; i <= n; i++) {
        a[i-1] = i;
        c[i-1] = i;
    }

    while (counter == -1 || see(a,c,n)) {
        counter++;
        int x = 0;
        for (int i = 0; i < n/2; i++) {
            b[x+1] = a[i];
            b[x] =a[i + n/2];
            x+=2;
        }

        for (int i = 0; i < n; i++){
            a[i] = b[i];
            cout << a[i] << " ";
        }
        cout << endl;
    }

    cout << counter << endl;






    return 0;
}
