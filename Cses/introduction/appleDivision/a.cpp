#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[20];
ll mn; 
ll x, y; 

int main (int argc, char *argv[]){
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    mn = sum; 
    for (int i = 0; i < (1<<n)-1; i++) {
        x = 0; y = 0;
        for (int j = 0; j < n; j++) {
            if(i & (1<<j)) 
                x += a[j];
            else 
                y += a[j];
        }
        if (mn > abs(x-y)) {
            mn = abs(x-y);
        }
    }
    cout << mn << endl;
    return 0;
}

