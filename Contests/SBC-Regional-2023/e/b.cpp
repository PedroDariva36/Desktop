#include <bits/stdc++.h>

using namespace std;


int digits(int x){
    int sum = 0;
    int aux = 0;
    while (x > 0) {
        aux = x % 10;
        sum += aux;
        x = x / 10;
        cout << aux << endl;
    }
    cout << sum << endl;
    return sum;
}

int main (int argc, char *argv[]){
    
    cout << digits(100) << endl;

    return 0;
}
