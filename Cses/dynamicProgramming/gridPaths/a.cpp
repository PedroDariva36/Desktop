#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;

char g[1000][1000];
ll a[1000][1000];
int n;
const unsigned ll mod = 1e9+7;


ll solve(int x, int y){
    
    if (x > n-1 || x < 0) return 0; 
    if (y > n-1 || y < 0) return 0;
    if (g[x][y] == '*') return 0;
    if (a[x][y] != -1) return a[x][y];
    if(x == n-1 && y == n-1) return 1;


    ll count = (solve(x+1,y)+solve(x,y+1)) % mod;
    a[x][y] = count;
    return count;
}

int main (int argc, char *argv[]){
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            a[i][j] = -1;
        }
    }
    
    cout << solve(0,0) << endl;



    
    return 0;
}
