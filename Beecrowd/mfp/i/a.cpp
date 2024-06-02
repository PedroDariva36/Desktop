#include <bits/stdc++.h>

using namespace std;


int main (int argc, char *argv[]){
    int sum = 0;
    int aux;
    for (int i = 0; i < 7; i++) {
        cin >> aux; 
        sum += aux; 
    }
    cin >> aux;
    cout << ((sum % 2 == aux)? "N?" : "S") << endl;





    return 0;
}
