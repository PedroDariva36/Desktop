#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[]){
    vector<int>a;
    int n, old,sum = 0,counter = 0;
    cin >> n;
    old = n;
    while(n > 0) {
        counter++;
        int mod = n % 10;
        a.push_back(mod);   
        n = n / 10;
    }    
    for (auto i : a) sum += pow(i,counter);

    if (sum == old) cout <<"O numero é um número de Armstrong"<<endl;
    else cout <<"O numero não é um número de Armstrong"<<endl;

    
    return 0;
}
