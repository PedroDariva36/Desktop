#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]){
    
    int n, sum, average;

    while (cin >> n) {
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
       
        average = 0;
        for (int i = 0; i < n; i++)
            average += a[i];
        
        if (average % n != 0) {
            cout << -1 << '\n';
            continue;
        }

        average = average / n;
        sum = 0;
        
        for (int i = 0; i < n; i++)
            sum += abs(average - a[i]);
        cout << sum/2 + 1 << '\n';

    }

    return 0;
}
