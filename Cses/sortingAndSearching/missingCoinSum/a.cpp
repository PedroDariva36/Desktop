#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <unistd.h>
#include <vector>

using namespace std;

int main (int argc, char *argv[]){
    int n;
    long aux;
    vector<long> a;
    cin >> n;
    for (int i = 0;i < n; i++) {
        cin >> aux;
        a.push_back(aux);
    }
    sort(a.begin(),a.end());
    
    if (a[0] > 1) {
        cout << 1 << endl;
        return 0;
    }

    long sum = 0;
    for (auto &i : a) {
        //cout << i << " : " << sum << endl;
        if (i - sum > 1) {
            cout << sum + 1 << endl;
            return 0;
        }
        sum += i;
    } 

    cout << sum+1 << endl;

    return 0;
}
