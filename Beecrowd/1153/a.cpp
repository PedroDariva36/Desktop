#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]){
    int n;
    cin >> n;
    long long x = 1;
    for (int i = 1; i <= n; i++) x *= i;
    cout << x << endl;

    return 0;
}
