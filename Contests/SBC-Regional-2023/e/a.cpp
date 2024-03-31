#include <bits/stdc++.h>
#define ll long long

using namespace std;

long a[10123456]; 

int digits(int x){
    int sum = 0;
    int aux = 0;
    while (x > 0) {
        aux = x % 10;
        sum += aux;
        x = x / 10;
    }
    return sum;
}


ll solve(int x, long k){}


int main (int argc, char *argv[]){
    
    int n;
    long k;

    cin >> n >> k;
    
    for(int i = 0; i < n; i++) cin >> a[i]; 
    
    ll sum = 0;
    for (int i = 0; i < n; i++){ 
        sum += solve(i,k);
    };
    

    cout << sum << endl;

    return 0;
}
