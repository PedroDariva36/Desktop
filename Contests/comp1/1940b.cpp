#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]){
    

    int j, r, aux;
    cin >> j >> r;    
    
    int array[j];
    for (int i = 0; i < j; i++) {
        array[i] = 0;
    }


    
    while (r--) {
        for (int i = 0; i < j; i++) {
            cin >> aux;
            array[i] += aux;
        }
    }
    //for (int i = 0; i < j; i++) {
    //    cout << array[i] <<" ";
    //}
    //return 0;
    
    int mx = -1;
    for (int k = 0; k < j; k++) {
            mx = max(array[k],mx);
    }
    
    for (int i = j-1; i >= 0; i--) {
        if (array[i] == mx) {
            cout << i+1 << endl;
            break;
        }
    }
    return 0;
}
