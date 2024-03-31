#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main (int argc, char *argv[])
{
    
    ll matrix[1000][1000];
    int n,x;
    
    for (int i = 0; i < n; i++) {       
        for (int j = 0; j < n; j++){
            cin >> x;
            matrix[i][j] = x;
        }
    }

    return 0;
}
