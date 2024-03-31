#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

int main (int argc, char *argv[]){
    
    long long n,m, aux;

    int med;


    cin >> n >> m >> aux;
    med = aux;

    int last = 0;
    vector<int> v;
    for (int i = 1; i < 30; i++) {
        cin >> aux;
        med += aux;
        v.push_back(aux);
    }
    int sum = med;
    int day_count = 1;
    while(m > n){
    aux = med/30;
    if(aux < (float) med/30)
        aux++;
    // upper round == aux

    //add aos inscri
    n+=aux;
    med = sum+aux-v[last];
    last++;
    day_count++;
    }
    cout << day_count;


    if(aux < (float)med/30)
        aux++;
    med = aux;

    aux = (m-n)/med; 
    if(aux < (float)(m-n)/med){
        aux++;
    }

    
    cout << aux << endl;

    return 0;
}
